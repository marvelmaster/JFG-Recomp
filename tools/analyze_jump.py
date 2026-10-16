"""Offline jump trajectories; no game execution or log modification.

Example: python tools/analyze_jump.py runlogs/ab60_m*.trace.log --out runlogs/jumps
Writes OUT.json (all updates, jumps and common-VI comparisons), OUT.csv (all
updates), OUT.compare.csv. Script milliseconds select jump windows only; all
physics measurements/comparisons use the recorded game timer, in VI ticks.
JFG_PLAYER is a pre-update position. delta belongs to the forthcoming update;
time differences, not that delta, determine position secants. No VI frequency
or physics constants are assumed. Ground contact is inferred from return to
the pre-press height, unsuitable for ledges/slopes. Missing landings stay null.

Optional future records: JFG_PHYSICS frame=N key=value ... are retained verbatim
as fields (multiple records per frame). A numeric vy at phase=takeoff supplies
explicit v0; all other v0 values are labelled quadratic position estimates.
Current site=0/1 records additionally audit the measured float32 free-flight
recurrence, including velocity recovery from rounded displacement after moving.
Optional --model JSON requires v0, gravity, step_vi and velocity_first (bool),
in units/VI, units/VI^2. This simulates the supplied Euler recurrence exactly,
not an asserted model of the game. Model y starts at zero and has no collision.
"""
import argparse
import csv
import glob
import json
import math
import re
import struct
from pathlib import Path


def fields(line):
    return dict(re.findall(r"(\w+)=([^\s]+)", line))


def load(path):
    rows, diagnostics = {}, {}
    for line in Path(path).read_text(errors="replace").splitlines():
        if line.startswith("JFG_GAMEPLAY "):
            f = fields(line)
            row = {k: int(f[k]) for k in ("frame", "ms", "on", "delta", "time")}
            rows[row["frame"]] = row
        elif line.startswith("JFG_PLAYER "):
            f = fields(line)
            row = rows.get(int(f["frame"]))
            if row is not None:
                row.update(zip(("x", "y", "z"), map(float, f["xyz"].split(","))))
        elif line.startswith(("JFG_PHYSICS ", "JFG_VERTICAL_STEP ")):
            f = fields(line)
            if line.startswith("JFG_VERTICAL_STEP "):
                f["record_type"] = "vertical_step"
            if "frame" in f:
                diagnostics.setdefault(int(f["frame"]), []).append(f)
    result = list(rows.values())
    previous = None
    for r in result:
        r["physics"] = diagnostics.get(r["frame"], [])
        if "y" in r:
            dt = r["time"] - previous["time"] if previous else 0
            r["position_dt_vi"] = dt if previous else None
            r["vy_secant_units_per_vi"] = (r["y"] - previous["y"]) / dt if dt > 0 else None
            r["previous_delta_matches_dt"] = dt == previous["delta"] if previous else None
            previous = r
    return result


def f32(value):
    return struct.unpack("!f", struct.pack("!f", value))[0]


def exact_field(record, name):
    bits = record.get(name + "bits")
    return struct.unpack("!f", bytes.fromhex(bits))[0] if bits else f32(float(record[name]))


def physics_jump(trajectory, tolerance):
    """Audit observed operands and free-flight f32 recurrence with velocity recovery.

    This model's stated scope is k=0/helper=0,0. Collision landing transitions
    are exported separately and excluded from the free-flight maximum error.
    """
    pairs = []
    for r in trajectory:
        p = {d.get("site"): d for d in r["physics"] if d.get("record_type") != "vertical_step"}
        if "0" in p and "1" in p:
            pairs.append((r, p["0"], p["1"]))
    if len(pairs) < 2:
        return None
    first = pairs[0][1]
    y, v = exact_field(first, "y"), exact_field(first, "vy")
    out = {"scope": "float32 free flight, k=0 helper=0,0; optional traced half-gravity dy correction and guarded velocity restoration",
           "launch_pregravity_vy": v, "launch_hold": int(first["hold"]), "launch_countdown": int(first["countdown"]),
           "launch_state": int(first["state"]), "samples": []}
    for i, (row, pre, post) in enumerate(pairs[:-1]):
        if float(pre["k"]) != 0 or pre["helper"] != "0,0":
            out["unsupported_frame"] = row["frame"]
            break
        dt, g = f32(float(pre["delta"])), f32(float(pre["g"]))
        steps = {d["site"]: d for d in row["physics"] if d.get("record_type") == "vertical_step"}
        applied = steps.get("2", {}).get("applied") == "1"
        restored = steps.get("3", {}).get("restored") == "1"
        decrement = f32(g * dt)
        new_v = f32(v - decrement)
        dy = f32(new_v * dt)
        if applied:
            dy = f32(dy - f32(decrement * 0.5))
        new_y = f32(y + dy)
        recovered_v = new_v if restored else f32(f32(new_y - y) / dt)
        next_row, next_pre, _ = pairs[i + 1]
        observed_y, observed_v = exact_field(next_pre, "y"), exact_field(next_pre, "vy")
        contact = next_row["height"] <= tolerance and next_row["phase_vi"] > 0
        out["samples"].append({"frame": row["frame"], "phase_vi": row["phase_vi"], "delta": dt,
            "dy_correction_applied": applied, "velocity_restored": restored,
            "g": g, "gravity_operand": float(pre["operand"]), "gravity_operand_model_error": f32(float(pre["operand"])) - decrement,
            "pregravity_vy": exact_field(pre, "vy"), "postgravity_vy": exact_field(post, "vy"),
            "postgravity_model_error": exact_field(post, "vy") - new_v,
            "next_y_model": new_y, "next_y_observed": observed_y, "next_y_error": observed_y - new_y,
            "next_vy_model": recovered_v, "next_vy_observed": observed_v, "next_vy_error": observed_v - recovered_v,
            "landing_contact_transition": contact})
        y, v = new_y, recovered_v
        if contact:
            break
    free = [s for s in out["samples"] if not s["landing_contact_transition"]]
    for field in ("gravity_operand_model_error", "postgravity_model_error", "next_y_error", "next_vy_error"):
        out["max_abs_" + field] = max((abs(s[field]) for s in free), default=None)
    out["free_flight_steps"] = len(free)
    return out


def jump(rows, press, end, tolerance, class_width):
    points = [r for r in rows if "y" in r and press - 300 <= r["ms"] < end]
    before = [r for r in points if r["ms"] < press]
    if not before:
        return {"press_ms": press, "status": "missing_prepress_position"}
    base = before[-1]["y"]
    take = next((i for i, r in enumerate(points) if r["ms"] >= press and r["y"] > base + tolerance), None)
    if take is None or take == 0:
        return {"press_ms": press, "status": "no_rise"}
    # Last observed position before the first rise is the reproducible phase anchor.
    anchor = points[take - 1]
    apex_i = max(range(take, len(points)), key=lambda i: points[i]["y"])
    landing_i = next((i for i in range(apex_i + 1, len(points)) if points[i]["y"] <= base + tolerance), None)
    stop = landing_i + 1 if landing_i is not None else len(points)
    trajectory = [dict(r, phase_vi=r["time"] - anchor["time"], height=r["y"] - base) for r in points[take - 1:stop]]
    out = {"press_ms": press, "status": "landed" if landing_i is not None else "landing_not_observed",
           "anchor_frame": anchor["frame"], "anchor_time_vi": anchor["time"], "base_y": base,
           "takeoff_bracket_vi": [0, points[take]["time"] - anchor["time"]],
           "apex_height": points[apex_i]["y"] - base,
           "apex_phase_vi": points[apex_i]["time"] - anchor["time"],
           "trajectory": trajectory}
    first = trajectory[:3]
    v0, source = None, "unavailable"
    if len(first) == 3:
        a, b, c = first
        dt1, dt2 = b["phase_vi"], c["phase_vi"] - b["phase_vi"]
        if dt1 > 0 and dt2 > 0:
            s1, s2 = (b["height"] - a["height"]) / dt1, (c["height"] - b["height"]) / dt2
            acceleration = 2 * (s2 - s1) / (dt1 + dt2)
            v0 = s1 - acceleration * dt1 / 2
            out["initial_acceleration_estimate_units_per_vi2"] = acceleration
            source = "inferred_quadratic_derivative_at_last_prerise_sample"
    for r in trajectory[:2]:
        for p in r["physics"]:
            if p.get("phase") == "takeoff" and "vy" in p:
                v0, source = float(p["vy"]), "explicit_JFG_PHYSICS_vy_takeoff"
    out.update(v0=v0, v0_source=source, v0_class=round(v0 / class_width) * class_width if v0 is not None else None)
    audit = physics_jump(trajectory, tolerance)
    if audit:
        out["physics_audit"] = audit
        out["position_inferred_v0"] = v0
        out.update(v0=audit["launch_pregravity_vy"], v0_source="explicit_site0_pregravity_at_last_prerise_sample",
                   v0_class=round(audit["launch_pregravity_vy"] / class_width) * class_width)
    if landing_i is not None:
        pre, land = points[landing_i - 1], points[landing_i]
        out["landing_phase_vi"] = land["time"] - anchor["time"]
        out["airtime_bracket_vi"] = [max(0, pre["time"] - points[take]["time"]), land["time"] - anchor["time"]]
        out["landing_velocity"] = {"value": pre["vy_secant_units_per_vi"], "source": "last_full_precontact_interval_secant_units_per_vi"}
    else:
        out.update(landing_phase_vi=None, airtime_bracket_vi=None, landing_velocity=None)
    return out


def model(spec):
    dt = spec["step_vi"]
    if dt <= 0 or not isinstance(spec["velocity_first"], bool):
        raise ValueError("model requires positive step_vi and boolean velocity_first")
    y, v, values = 0.0, spec["v0"], []
    for n in range(int(spec.get("duration_vi", 120) / dt) + 1):
        values.append({"phase_vi": n * dt, "height": y, "vy": v})
        if spec["velocity_first"]:
            v += spec["gravity"] * dt
        y += v * dt
        if not spec["velocity_first"]:
            v += spec["gravity"] * dt
    return values


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("traces", nargs="+")
    p.add_argument("--out", required=True, help="new output file prefix (existing outputs are refused)")
    p.add_argument("--jumps", default="1000,2600")
    p.add_argument("--window-ms", type=int, default=1500)
    p.add_argument("--height-tolerance", type=float, default=0.5)
    p.add_argument("--v0-class-width", type=float, default=0.5)
    p.add_argument("--model", help="JSON specification of a supplied recurrence")
    args = p.parse_args()
    if args.v0_class_width <= 0:
        p.error("--v0-class-width must be positive")
    paths = sorted({str(Path(f)) for pattern in args.traces for f in glob.glob(pattern)})
    if not paths:
        p.error("no matching traces")
    targets = [Path(args.out + suffix) for suffix in (".json", ".csv", ".compare.csv")]
    if any(t.exists() for t in targets):
        p.error("output already exists; choose another --out prefix")
    result = {"units": "positions in game units; time in recorded VI ticks; no assumed VI frequency", "v0_class_width": args.v0_class_width,
              "limitations": "v0 inferred from first three positions; phase origin and contact bracketed by observations; classes are estimates, not proven launch states", "runs": [], "comparisons": []}
    presses = sorted(map(int, args.jumps.split(",")))
    for path in paths:
        rows = load(path)
        jumps = [jump(rows, press, min(press + args.window_ms, presses[i + 1] if i + 1 < len(presses) else math.inf), args.height_tolerance, args.v0_class_width) for i, press in enumerate(presses)]
        result["runs"].append({"trace": path, "updates": rows, "jumps": jumps})
    for i, a in enumerate(result["runs"]):
        for b in result["runs"][i + 1:]:
            for ja in a["jumps"]:
                for jb in b["jumps"]:
                    if ja.get("v0_class") is None or jb.get("v0_class") is None:
                        continue
                    ta = {r["phase_vi"]: r for r in ja["trajectory"]}
                    tb = {r["phase_vi"]: r for r in jb["trajectory"]}
                    if {next(iter(ta.values()))["on"], next(iter(tb.values()))["on"]} != {0, 1}:
                        continue
                    common = sorted(ta.keys() & tb.keys())
                    result["comparisons"].append({"a": a["trace"], "b": b["trace"], "press_a": ja["press_ms"], "press_b": jb["press_ms"],
                        "v0_class_a": ja["v0_class"], "v0_class_b": jb["v0_class"], "same_estimated_v0_class": ja["v0_class"] == jb["v0_class"],
                        "samples": [{"phase_vi": t, "height_a": ta[t]["height"], "height_b": tb[t]["height"], "height_b_minus_a": tb[t]["height"] - ta[t]["height"]} for t in common]})
    if args.model:
        spec = json.loads(Path(args.model).read_text())
        result["supplied_model"] = {"spec": spec, "samples": model(spec)}
    targets[0].write_text(json.dumps(result, indent=2, allow_nan=False) + "\n")
    columns = ["trace", "frame", "ms", "on", "delta", "time", "x", "y", "z", "position_dt_vi", "vy_secant_units_per_vi", "previous_delta_matches_dt", "physics", "jump_press_ms", "phase_vi", "height"]
    with targets[1].open("w", newline="") as f:
        w = csv.DictWriter(f, columns)
        w.writeheader()
        for run in result["runs"]:
            phases = {r["frame"]: {"jump_press_ms": j["press_ms"], "phase_vi": r["phase_vi"], "height": r["height"]}
                      for j in run["jumps"] for r in j.get("trajectory", [])}
            for r in run["updates"]:
                w.writerow(dict(r, **phases.get(r["frame"], {}), trace=run["trace"], physics=json.dumps(r["physics"])))
    with targets[2].open("w", newline="") as f:
        columns = ["a", "b", "press_a", "press_b", "v0_class_a", "v0_class_b", "same_estimated_v0_class", "phase_vi", "height_a", "height_b", "height_b_minus_a"]
        w = csv.DictWriter(f, columns)
        w.writeheader()
        for pair in result["comparisons"]:
            for sample in pair["samples"]:
                w.writerow(dict({k: v for k, v in pair.items() if k != "samples"}, **sample))
    for run in result["runs"]:
        summaries = [{k: ({a: b for a, b in v.items() if a != "samples"} if k == "physics_audit" else v)
                      for k, v in j.items() if k != "trajectory"} for j in run["jumps"]]
        print(json.dumps({"trace": run["trace"], "jumps": summaries}))


if __name__ == "__main__":
    main()
