#include <bits/stdc++.h>
		
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
#define var(a,b)  __typeof(b) a = b
#define rep(i,n)  for(int i = 0; (i) < (n); ++i)
#define rept(i,a,b) for(var(i,a); i < (b); ++i)
#define tr(v,it)  for(var(it,v.begin());it!=v.end();++it)
#define fill(a,val) memset(a,val,sizeof(a))
#define all(v) v.begin(),v.end()
 
#define get getchar_unlocked
 
//fast input
template<class T>
inline T scan_int() {int ip=getchar(),flag=1;T ret=0;for(;ip<'0'||ip>'9';ip=getchar())if(ip=='-'){flag=-1;ip=getchar();break;}for(;ip>='0'&&ip<='9';ip=getchar())ret=(ret<<3)+(ret<<1)+ip-'0';return flag*ret;}
#define scan_d() scan_int<int>()
#define scan_ld() scan_int<long int>()
#define scan_lld() scan_int<long long int>()
template <class T>
inline T scan_decimal(){char c;c = getchar();T flag=1.0;long long int t = 0;for(;c<'0'||c>'9';c=getchar())if(c=='-'){flag=-1.0;c=getchar();break;}while(c<='9' && c>='0'){t=(t<<3)+(t<<1)+c-'0';c = getchar();}long long int d=0,i=1;if(c=='.'){c = getchar();while(c<='9' && c>='0'){i=(i<<3)+(i<<1);d=(d<<3)+(d<<1)+c-'0';c = getchar();}}return ((T)t + ((T)d)/i)*flag;}
#define scan_f() scan_decimal<float>()
#define scan_lf() scan_decimal<double>()
inline void scan_str(char *str){register char c = 0;register int i = 0;while (c < 33)c = getchar();while (c != '\n' && c != EOF){str[i] = c;c = getchar();i = i + 1;}str[i] = '\0';}
//end of fast input
 
//fast output
#define put putchar_unlocked
char output_buffer[21];
template <class T>
inline void print_int(T n) {if(n<0){n=-n;putchar('-');}int i=21;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
#define print_d print_int<int>
#define print_ld print_int<long int>
#define print_lld print_int<long long int>
template <class T>
inline void println_int(T n) {print_int(n);putchar('\n');}
#define println_d println_int<int>
#define println_ld println_int<long int>
#define println_lld println_int<long long int>
template <class T>
inline void printsp_int(T n,char ch) {print_int(n);putchar(ch);}
#define printsp_d printsp_int<int>
#define printsp_ld printsp_int<long int>
#define printsp_lld printsp_int<long long int>
inline void print_str(char *str){char* temp=str;while((*temp)!='\0'){putchar(*temp);temp++;}}
inline void println_str(char *str){print_str(str); putchar('\n');}
//end of fast outputchar
 
#define MAXN 10009
 
int sizex,sizey;
int id[MAXN], best[MAXN];
 
void makeset() {
	rep(i, MAXN)
		id[i] = i;
}
 
inline int root (int i,int &size)
{
	size = 0;
	while(i != id[i])
	{
		id[i] = id[id[i]];
		i = id[i];
		size++;
	}
	return i;
}
 
// joining the dishes of chef y to x
inline void qunion(int x,int y)
{
	x = root(x,sizex);
	y = root(y,sizey);
	
	id[y] = x;
}
 
inline bool qfind(int x,int y)
{
	return (root(x,sizex) == root(y,sizey));
}
 
int n, q, flag;
 
int main() {

    int t = scan_d();
    int x, y, rootx, rooty;
 
    while(t--) {
    	makeset();
 
    	n = scan_d();
    	rept(i, 1, n+1) best[i] = scan_d();
 
    	q = scan_d();
 
    	while(q--) {
    		flag = scan_d();
 
    		if(flag == 1) {
    			x = scan_d();
    			println_d(root(x, sizex));
    		}
    		else {
    			x = scan_d();
    			y = scan_d();
 
    			if(qfind(x, y)) {
    				printf("Invalid query!\n");
    			}
    			else {
    				rootx = root(x, sizex);
    				rooty = root(y, sizey);
 
    				if(best[rootx] > best[rooty]) {
    					qunion(rootx, rooty);
    				}
    				else if(best[rooty] > best[rootx]) {
    					qunion(rooty, rootx);
    				}
    			}
    		}
    	}
 
    }
 
 
	return 0;
} 

