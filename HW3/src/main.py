from time import perf_counter

from src.container import Container

MAX_RANDOM_COUNT = 10000


def main(*args: str) -> float:
    file_input = args[0] == "-f"
    input_file = None
    random_elements_count = None
    output_file = None
    start = None
    try:
        try:
            if file_input:
                input_file = open(args[1], "r")
            else:
                random_elements_count = int(args[1])
                if random_elements_count < 0 or random_elements_count > \
                        MAX_RANDOM_COUNT:
                    raise ValueError
            output_file = open(args[2], "w")
        except OSError:
            print("Invalid input/output file")
            exit(1)
        except ValueError:
            print("Invalid count of random elements")
            exit(1)
        start = perf_counter()
        container = Container.from_file(
            input_file) if file_input else Container.from_random_elements(
            random_elements_count)
        container.output(output_file)
        print("\n", file=output_file)
        container.move_function(output_file)
    except Exception as exception:
        print(*exception.args, file=output_file)
    finally:
        if file_input:
            input_file.close()
        output_file.close()
        return perf_counter() - start
