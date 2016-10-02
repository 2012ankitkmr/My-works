//source https://github.com/pin3da/Programming-contest/blob/master/solved/ICPCLivearchive/4682%20-%20XOR%20Sum/solution.cc
#include<bits/stdc++.h>
using namespace std;
 
struct trie{
	int info;
	struct trie *son[2];
};
 
int i,j,n,a[400005],b[400005];
int maxr[400005], maxl[400005], p[30];
struct trie *root;
 
inline void insert(int v) {
 
	struct trie *aux=root;
	for (int i=27; i>=0; --i) {
	  int bit=0;
	  if ( (v&p[i])>0 ) bit=1;
	  if (aux->son[bit]==0) aux->son[bit]=(struct trie *) calloc(1,sizeof(struct trie));
	  aux=aux->son[bit];
    }
 
    aux->info=v;
 
}
 
inline int find(int v) {
 
   struct trie *aux=root;
 
   for (int i=27; i>=0; --i) {
	  int bit=0;
	  if ( (v&p[i])>0 ) bit=1;
	  if (aux->son[1-bit]!=0) aux=aux->son[1-bit];
	  else aux=aux->son[bit];
    }
 
   return (v^aux->info);
 
}
 
int main(void) {
 
	scanf("%d",&n);
 
	p[0]=1;
	for (i=1; i<30; ++i) p[i]=2*p[i-1];
 
	 for (i=1; i<=n; ++i) {
	 scanf("%d",&a[i]);
	 b[i]=a[i];
	 a[i]^=a[i-1];
     }
 
     root=(struct trie *) calloc(1,sizeof(trie));
 
	 insert(0);
 
	 for (i=1; i<=n; ++i) {
       insert(a[i]);
       maxl[i]=find(a[i]);
	   if (maxl[i-1]>maxl[i])  maxl[i]=maxl[i-1];
	 }
 
	 root=(struct trie *) calloc(1,sizeof(trie));
	 insert(0);
     int sol=0;
     int maxaux=b[n];
 
	 for (i=n; i>=1; --i) {
	   b[i]^=b[i+1];
	   insert(b[i]);
	   maxr[i]=find(b[i]);
	   if (maxaux+maxl[i]>sol) sol=maxaux+maxl[i];
	   if (maxr[i]>maxaux) maxaux=maxr[i];
     }
 
    printf("%d\n",sol);
 
	return 0;
} 
