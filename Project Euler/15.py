from math import factorial

def sol(n = 20):
    k = n
    n *= 2

    return int(factorial(n) / (factorial(k) * factorial(n - k)))

print(sol(20))
