def MFKsnapsack(i, j):
    if F[i][j] < 0:
        if j < Ws[i]:
            value = MFKsnapsack(i-1, j)
        else:
            value = max(MFKsnapsack(i-1, j), Vs[i]+MFKsnapsack(i-1, j-Ws[i]))

        F[i][j] = value

    return F[i][j]

N, W = list(map(int, input().split()))
Ws = [0] * (N+1)
Vs = [0] * (N+1)

for i in range(1, N+1):
    Ws[i], Vs[i] = list(map(int, input().split()))

# Constroi tabela
F = []
for i in range(len(Vs)):
    line = []
    for j in range(W+1):
        if i == 0 or j == 0:
            line.append(0)
        else:
            line.append(-1)
    F.append(line)

print(MFKsnapsack(N, W))