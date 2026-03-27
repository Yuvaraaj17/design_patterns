import os
import subprocess
import sys
from pathlib import Path

# Config
SRC_DIR = Path(os.environ.get("SRC_DIR", "src"))  # default = src dir
OUT_DIR = Path("bin")

CXX = os.environ.get("CXX", "g++")
CXXFLAGS = os.environ.get(
    "CXXFLAGS",
    "-std=c++17 -O2"
).split()

OUT_DIR.mkdir(exist_ok=True)

failed = False

for file in SRC_DIR.glob("*.cpp"):
    output = OUT_DIR / file.stem
    if os.name == "nt":
        output = output.with_suffix(".exe")

    result = subprocess.run(
        [CXX, *CXXFLAGS, str(file), "-o", str(output)],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.PIPE,
        text=True
    )

    if result.returncode == 0:
        print(f"{file.name} ✓")
    else:
        failed = True
        print(f"{file.name} ✗")
        print(result.stderr.strip())

if failed:
    sys.exit(1)