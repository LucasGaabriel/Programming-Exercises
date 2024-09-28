a, k = input().split()

a = list(a)
k = int(k)

n = len(a)

for i in range(n-1):
    j = -1
    num = a[i]
    for x in range(i+1, n):
        if a[x] > num:
            num = a[x]
            j = x
        while(j >= 1 and a[j] > a[j-1] and k):
            a[j], a[j-1] = a[j-1], a[j]
            j -= 1
            k -= 1

print("".join(a))
