import math as m

if __name__ == '__main__':

    userIn = input().split()
    n = int(userIn[0])
    r = int(userIn[1])
    w = int(userIn[2])
    pythag = m.sqrt(r*r + w*w)

    for _ in range(n):
        x = float(input())

        if x > pythag:
            print("NE")
        else:
            print("DA")



