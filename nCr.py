def f(n):
	return reduce(lambda x,y:x*y,[1]+range(1,n+1))
t=int(raw_input())
while t:
	n=map(int,raw_input().split(' '))
	print f(n[0])/(f(n[1])*f(n[0]-n[1]))
	t=t-1