N = int(input())
stones = list(map(int, input().split()))

if N < 3:
    print(abs(stones[0] - stones[1]))
    exit()

tab = [0] * N;
tab[1] = abs(stones[1] - stones[0])
tab[2] = abs(stones[2] - stones[0])

for i in range(3, N):
    tab[i] = min( abs(stones[i]-stones[i-1]) + tab[i-1], abs(stones[i]-stones[i-2]) + tab[i-2])

print(tab[-1])
