a = [[1,2,3],[4,5,6],[7,8,9]]

for i in range(len(a)):
    a[i] = a[i][::-1]

for i in range(len(a)-1):
    for j in range(len(a[0])-i-1):
        a[i][j], a[-1-j][-1-i] = a[-1-j][-1-i], a[i][j]

print(a)