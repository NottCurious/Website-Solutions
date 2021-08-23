n = 1


def countDivisors(num):
    num = int(num * (num + 1) / 2)
    print(num)
    ns = []
    for i in range(1, int(num ** 0.5) + 2):
        if num % i == 0:
            ns.append(i)

    for numb in ns:
        quo = num / numb

        if quo not in ns:
            ns.append(int(quo))

    return len(ns)


while countDivisors(n) <= 500:
    n += 1

print("\n" + str(int(n * (n + 1) / 2)))
print(n)
