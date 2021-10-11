import filecmp
import os
import subprocess
import time

program = "./task"
testCount = 12
randomTestCount = 3


def run(name: str, test: bool = True):
    print(f"Test {name}...", end=" ")
    input_file = f"input/{name}.in"
    output_file = f"{name}.out"
    begin = time.perf_counter()
    subprocess.run((program, input_file, output_file), timeout=5)
    end = time.perf_counter()
    if not test or filecmp.cmp(output_file, f"output/{name}.out", shallow=False):
        print(f"OK ({round(end - begin, 3)} s.)")
    else:
        print(f"failed! See '{output_file}'")
        exit()
    os.remove(output_file)


for i in range(1, testCount + 1):
    run(str(i))
for i in range(1, randomTestCount + 1):
    run(f"rand{i}", test=False)
