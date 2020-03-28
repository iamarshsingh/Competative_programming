import random

def printrand(n):
	print(n)
	a = [random.randint(1,21) for i in range(n)]
	print(*a)

for i in range(5):
	printrand(random.randint(3,5))