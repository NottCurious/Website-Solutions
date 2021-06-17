def checkThing(a, b, c):
    if (a + b + c) == 1000 and (a ** 2 + b ** 2 - c ** 2) == 0:
        return True
    return False

a = 0
b = 0
c = 0

while not checkThing(a, b, c):
    a += 1

    if a >= b:
        b += 1
        a = 0

    if b >= c:
        c += 1
        b = 0

print(a, b, c)
print(a + b + c)
print(str(a * a + b * b) + '==' + str(c * c))
print(a * b * c)

# 200 375 425
# 1000
# 180625==180625
# 31875000
