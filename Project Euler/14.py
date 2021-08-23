def sol():
    n = 1000000
    largest = 0
    pre = 0

    for input in range(n):
        counter = 1
        number = input

        while number > 1:
            if number % 2 == 0:
                number /= 2
                counter += 1

            else:
                number = (3 * number) + 1
                counter += 1

        if counter > pre:
            largest = input
            pre = counter

        print("Currently on {}, Largest: {}".format(input, largest), end="\r")

    return largest


print(sol())
