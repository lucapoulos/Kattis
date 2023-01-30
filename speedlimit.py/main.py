t = int(input())
while t != -1:
    prevTime = 0
    total = 0
    for _ in range(t):
        num1, num2 = (int(s) for s in input().split())
        total += (num2 - prevTime) * num1
        prevTime = num2
    print(total, " miles")
    t = int(input())
