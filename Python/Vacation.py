N = int(input())
mat = [0] * N

for i in range(N):
    mat[i] = list(map(int, input().split()))

def maxHappiness(mat):
    happiness = []

    happiness.append(mat[0])

    for i in range(1, N):
        happiness.append([0, 0, 0])

        happiness[i][0] = mat[i][0] + max(happiness[i-1][1], happiness[i-1][2])
        happiness[i][1] = mat[i][1] + max(happiness[i-1][0], happiness[i-1][2])
        happiness[i][2] = mat[i][2] + max(happiness[i-1][0], happiness[i-1][1])

    return max(happiness[N-1][0], happiness[N-1][1], happiness[N-1][2])

print(maxHappiness(mat))