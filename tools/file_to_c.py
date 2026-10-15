"""Portable replacement for RT64's binary-to-C build helper."""

import re
import sys
from pathlib import Path


def main():
    if len(sys.argv) != 5:
        print(f"Usage: {sys.argv[0]} [input file] [array name] [output C file] [output C header]")
        return 1
    source, name, c_file, h_file = sys.argv[1:]
    if not re.fullmatch(r"[A-Za-z_][A-Za-z_0-9]*", name):
        raise ValueError(f"Invalid C array name: {name}")
    contents = Path(source).read_bytes()
    if not contents:
        raise ValueError(f"Input file is empty: {source}")
    declaration = (
        "#include <stddef.h>\n"
        f"extern const char {name}[{len(contents)}];\n"
    )
    size = f"extern const size_t {name}_size;\n"
    for output in (c_file, h_file):
        Path(output).parent.mkdir(parents=True, exist_ok=True)
    with Path(c_file).open("w", encoding="ascii", newline="\n") as output:
        output.write(declaration + f"const char {name}[{len(contents)}] = {{")
        # Match the signed char values emitted by the Windows C++ helper.
        for start in range(0, len(contents), 4096):
            output.write("".join(f"{b if b < 128 else b - 256}, " for b in contents[start:start + 4096]))
        output.write("};\n" + size)
        output.write(f"const size_t {name}_size = sizeof({name}) / sizeof({name}[0]);\n")
    Path(h_file).write_text(
        '#ifdef __cplusplus\n  extern "C" {\n#endif\n'
        + declaration + size + "#ifdef __cplusplus\n  }\n#endif\n",
        encoding="ascii", newline="\n",
    )
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (OSError, ValueError) as error:
        print(error, file=sys.stderr)
        sys.exit(1)
