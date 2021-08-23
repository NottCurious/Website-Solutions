def checkPalindrome(s):
    for i in range(len(s)):
        if s[i] != s[len(s) - i - 1]:
            return False

    return True


largest = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        if checkPalindrome(str(i * j)):
            largest = max(i * j, largest)

print(largest)
