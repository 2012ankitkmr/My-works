#include<bits/stdc++.h>
using namespace std;

#define MAX 100001
#define NIL 0
#define INF (1<<28)

/*check matching question*/
/* G is 1 indexed */
// dont forget this is for undirected graph 

vector<long int > G[MAX];
long int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {//initially push all of 'em
            dist[i] = 0;    //make distance for all of them 0 or reachable
            Q.push(i);
        }
        else dist[i] = INF;  //iff match is already done put them far away. 
    }
    dist[NIL] = INF;          //lood started from 1 so make this(0) INF tooo 
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {            
            len = G[u].size();      // length of connected edges
            for(i=0; i<len; i++) {  // for all i adj to u
                v = G[u][i];      
                if(dist[match[v]]==INF) {   // if matched qty is INF
                    dist[match[v]] = dist[u] + 1; //dis updated
                    Q.push(match[v]);  //pushed matched one]
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    
	memset(match,NIL);
	while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

int main()
{
	
	
	return 0;
}
