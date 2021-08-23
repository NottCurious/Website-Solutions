import os


def sol():
    file_path = os.path.join(os.path.dirname(__file__), "13num.txt")

    with open(file_path) as f:
        return str(sum([int(line) for line in f]))[:10]


print(sol())
