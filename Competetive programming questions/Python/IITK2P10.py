
mod=int(10**9+7)
t=int(input())
while t>0:
    t-=1
    k=int(input())
    n=int(input())
    if n == 1:
        print 1
    elif n == 2:
        print k
    else:
        m=pow(2,n-3,mod-1)
        print pow(k,m,mod)
