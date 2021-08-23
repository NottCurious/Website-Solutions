import time


def sum_of_digits(num: int):
    sum = 0
    num_string = str(num)
    list_num = list(num_string)

    for i in list_num:
        sum += int(i)

    return sum


# print(2 ** 1000)
print(sum_of_digits(2 ** 1000))
