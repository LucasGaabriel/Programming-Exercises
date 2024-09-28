s = input()
hello = 'hello'

i=0
for l in s:
    if l == hello[i]:
        i += 1
    if(i == 5): 
        break

if(i == 5):
    print("YES")
else:
    print("NO")