arr = [ i for i in range(1,5001) ]
for i in range(1,5001):
	sum = 0
	for j in range(1,i+1):
		sum = sum + ((i*i)//j)
	#print(sum)
	sum = (2*sum) - (i*i)
	arr[i-1] = sum
print(arr)