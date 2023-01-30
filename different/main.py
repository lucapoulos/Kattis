from sys import stdin

for line in stdin:
    n1, n2 = (int(s) for s in line.split())
    print(abs(n1 - n2))
