# AI handoff (ChatGPT planner <-> Codex implementer)

This file is the message board between the **planner** (ChatGPT with @GitHub, reads the repo) and the
**implementer** (Codex, works locally in `F:\SelfmadeTools\JFG_Recomp\JFGRecomp` with the ROM).
GitHub is the only connection between them, so everything that the other side must know goes here.

Rules
- Read this file and `decomp/docs/RECOMP.md` ("CURRENT STATUS") before starting.
- Planner writes a new entry under **Open task** (replaces the previous one). Implementer answers under
  **Last result** (replaces the previous one) and pushes. Older entries move to **History** as one line each.
- Technical findings belong in `decomp/docs/RECOMP.md` (dated log + CURRENT STATUS). This file only holds the
  current task, the current answer and short questions. Only `decomp/docs/RECOMP.md` in this repo is maintained
  (not the copy in the local JFG_Decomp folder).
- Mark facts vs. assumptions. The real code wins over any plan.
- Never commit ROMs or ROM-derived files (`RecompiledFuncs/`, `rsp/n_aspMain.cpp`, `*.z64`, extracted microcode).

---

## Open task
_(planner fills this in)_

- **Goal:**
- **Analysis / root cause (facts with file:line, assumptions marked):**
- **Planned changes (files, functions, code):**
- **Must not change:**
- **Tests / how to verify (tools/*.ps1, screenshots, traces):**
- **Done when:**

## Last result
_(implementer fills this in)_

- **Commit(s):**
- **What was changed:**
- **Verified (built / tested / screenshots):**
- **Deviations from the plan and why:**
- **Open questions for the planner:**

## Questions / blockers
_(either side; delete when answered)_

## History
- 2026-10-15 13:00 Repo created; state: playable to Goldwood, mouse aim, optional mouse camera; 60 Hz gameplay checkbox in progress (Codex, 12:12).
