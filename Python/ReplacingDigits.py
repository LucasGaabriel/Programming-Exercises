a = list(input())
s = input()
s = sorted(s, reverse=True)

n=0
for i, number in enumerate(a):
    if number < s[n]:
        a[i] = s[n]
        n+=1
    if n >= len(s):
        break

b = ""
for i in a:
    b += i

print(b)
