import sys
t, w = map(int, input().split())
for _ in range(t):
	print(1)
	sys.stdout.flush()
	a = int(input())
	if a == -1:
		break
	print(2)
	sys.stdout.flush()
	b = int(input())
	if b == -1:
		break
	for i in range(0,b-a+1):
		if 
	print(1)
	sys.stdout.flush()
	c = int(input())
	if c == -1:
		break
	r1 = c-((b-a))
	print(2)
	sys.stdout.flush()
	d = int(input())
	if d == -1:
		break
	r2 = d-c-(2*r1)
	print(3)
	sys.stdout.flush()
	e = int(input())
	if e == -1:
		break
	r3 = e-d-(4*r1)	
	print(4)
	sys.stdout.flush()
	f = int(input())
	if f == -1:
		break
	r4 = f-e-(8*r1)-(2*r2)
	r5 = 0
	r6 = 0
	here = False
	i=r1
	j=r2
	k=r3
	l=r4
	for m in range(0,101):
		n = b-a - (i+j+k+l+m)
		if ((576460752303423488*i + 536870912*j + 524288*k + 16384*l + 2048*m + 512*n)%9223372036854775808)==a:
			r1 = i
			r2 = j
			r3 = k
			r4 = l
			r5 = m
			r6 = n
			here = True
		if (here==True):
			break
	print(r1,r2,r3,r4,r5,r6)
	sys.stdout.flush()
	c = int(input())
	if c==-1:
		break