n = int(input())

A = 0
G = 0

for i in range(n):
    ai, gi = map(int, input().split())

    if(A + ai - G <= 500):
        print("A", end='')
        A += ai
    else:
        print("G", end='')
        G += gi
        
print()