print(10000)
for i in range(1,101):
    for j in range(1,101):
        print(j, i)
        k = [ i for i in range(1,j+1)]
        print(*k)