n = 600851475143


def checkPrime(num):
    for n in range(2, num):
        if num % n == 0:
            return False

    return True


for i in range(1, n - 1):
    if n % i == 0:
        if checkPrime(i):
            print(i)
