def findFibonacciNumbers():
     num = [] old = 0 new = 1 temp = old + new;
while temp < 4000000:
        num.append(temp)
        old = new
        new = temp
        temp = old + new

    return num

def findSum(nums):
    sum = 0

    for num in nums:
        if num % 2 == 0:
            sum += num

    print(sum)

fib = findFibonacciNumbers()
findSum(fib)
#print(fib)
