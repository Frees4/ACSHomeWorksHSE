from os import remove

from src.main import main

TEST_COUNT = 10
RANDOM_TESTS = (20, 1000, 10000)


def compare_files(file_name_1: str, file_name_2: str) -> bool:
    with open(file_name_1, 'r') as file_1, open(file_name_2, 'r') as file_2:
        while True:
            line_1 = file_1.readline()
            line_2 = file_2.readline()
            if line_1 == line_2 == '':
                return True
            if line_1.rstrip("\r\n") != line_2.rstrip("\r\n"):
                return False


def run(name: str) -> None:
    print(f"Test {name}...", end=" ")
    output_file = f"{name}.out"
    execution_time = main("-f", f"input/{name}.in", output_file)
    if compare_files(output_file, f"output/{name}.out"):
        print(f"OK ({execution_time:f} s.)")
    else:
        print(f"failed! See '{output_file}'")
        exit()
    remove(output_file)


def run_random(elements_count: int) -> None:
    print(f"Testing container with {elements_count} random elements...",
          end=" ")
    output_file = f"random{elements_count}.out"
    execution_time = main("-n", str(elements_count), output_file)
    print(f"({execution_time:f} s.)")
    remove(output_file)


for i in range(1, TEST_COUNT + 1):
    run(str(i))
for count in RANDOM_TESTS:
    run_random(count)
