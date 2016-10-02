#include<cstdio>
#define Max 100001
 
 
 
inline void readint(int &a)
{
    register int c; 
    a = 0;
	do c = getchar_unlocked(); while(c < '0');
	do{
		a = (a << 1) + (a << 3) + c - '0';
		c = getchar_unlocked();
	}while(c >= '0');
}
 
inline void printint(int a)
{
	char s[11];
	int t = -1;
	
	do{
		s[++t] = a % 10 + '0';
		a /= 10;
	}while(a > 0);
	
	while(t >= 0)putchar_unlocked(s[t--]);
	putchar_unlocked('\n');
}
 
struct SegmentTree
{
	int noOnes;
	int noTwos;
	int rem;
}st[Max << 2];
 
void update(int id,int l,int r,int ql,int qr)
{
	if(ql > r || qr < l)return;
	
	if(ql <= l && qr >= r)
	{
		int temp = st[id].noOnes;
		st[id].noOnes = (r - l + 1) - st[id].noOnes - st[id].noTwos;
		st[id].noTwos = temp;
		st[id].rem = (st[id].rem + 1) % 3;
		return;
	}
 
	int m = (l + r) >> 1;
	update( id << 1, l, m, ql, qr);
	update( id << 1 | 1, m + 1, r, ql, qr);
 
	st[id].noOnes = st[id << 1].noOnes + st[id << 1 | 1].noOnes;
	st[id].noTwos = st[id << 1].noTwos + st[id << 1 | 1].noTwos;
 
	if(st[id].rem == 1)
	{
		int temp = st[id].noOnes;
		st[id].noOnes = (r - l + 1) - st[id].noOnes - st[id].noTwos;
		st[id].noTwos = temp;
	}
	else if(st[id].rem == 2)
	{
		int temp = st[id].noTwos;
		st[id].noTwos = (r - l + 1) - st[id].noOnes - st[id].noTwos;
		st[id].noOnes = temp;
	}
}
 
int query(int id,int l,int r,int ql,int qr,int rem)
{
	if(ql > r || qr < l)return 0;
 
	if(ql <= l && qr >= r)
	{
		switch(rem)
		{
			case 1: return st[id].noTwos;
			case 2: return st[id].noOnes;
			default : return ((r - l + 1) - st[id].noOnes - st[id].noTwos);
		}
	}
 
	int m = (l + r) >> 1;
	rem = (rem + st[id].rem) % 3;
	return (query(id << 1, l, m, ql, qr, rem) + query( id << 1 | 1, m + 1, r, ql, qr, rem));
}
int main()
{
	int N, Q;
 
	readint(N);
	readint(Q);
 
	for(register int i = 0; i < Q; i++)
	{
		int q,ql,qr;
 
		readint(q);
		readint(ql);
		readint(qr);
 
		if(q)printint(query(1, 0, N - 1, ql, qr, 0));
		else update(1, 0, N - 1, ql, qr);
	}
	return 0;
} 
