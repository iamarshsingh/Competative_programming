import math

def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
  
def lcm(a,b): 
    return (a*b) / gcd(a,b) 

n,m,q = list(map(int,input().split()))
#print(n,m,q)
for _ in range(q):
	x1,y1,x2,y2 = list(map(int, input().split()))
	le = n*m
	base = lcm(n,m)
	bl1 = 0
	bl2 = 0
	b1=0
	b2=0
	if(x1==1):
		bl1 = (le/n)*y1
		b1 = (le/n)*(y1-1)
	else:
		bl1 = (le/m)*y1
		b1 = (le/m)*(y1-1)

	if(x2==1):
		bl2 = (le/n)*y2
		b2 = (le/n)*(y2-1)
	else:
		bl2 = (le/m)*y2
		b2 = (le/m)*(y2-1)

	#print(bl1, bl2, base, ((le/n)*(y1-1)), ((le/n)*(y2-1)))
	if((n==1 or (m==1 or ((bl1>(le/2) and bl2>(le/2)) or ((b1<=(le/2) and b2<=(le/2))) )))): 
	#	print(bl1, bl2, base, (bl1//base), (bl2//base))
		if(math.ceil(bl1/base) == math.ceil(bl2/base)):
			print("YES")
		else:
			print("NO")
	else:
		print("NO")