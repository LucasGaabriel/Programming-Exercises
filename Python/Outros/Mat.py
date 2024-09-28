r1, r2 = list(map(int, input().split()))
c1, c2 = list(map(int, input().split()))
d1, d2 = list(map(int, input().split()))

for i in range(1, 10):

    for j in range(1, 10):
        
        if j == i:
            continue

        for k in range(1, 10):

            if k == i or k == j:
                continue

            for l in range(1, 10):
                
                if l == i or l == j or l == k:
                    continue

                if(i+j == r1 and k+l == r2) and (i+k == c1 and j+l == c2) and (i+l == d1 and j+k == d2):
                    print(i, j)
                    print(k, l)
                    exit()

print(-1)