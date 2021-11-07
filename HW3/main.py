from sys import argv

import src.main

if __name__ == "__main__":
    if len(argv) == 4 and (
            argv[1] == "-f" or argv[1] == "-n" and argv[2].isdigit()):
        print(src.main.main(*argv[1:]), "s.")
    else:
        print("Usage: python main.py -f <input-file> <output-file>\n"
              "Or:    python main.py -n <random-elements-count> <output-file>")
