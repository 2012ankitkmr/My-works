#include <iostream>
    #include <cstdio>
    #include <cmath>
    #define gc getchar_unlocked
    using namespace std;
 
    struct Node{
      int wR[3];
      int sum;
    };
 
    int a[100005]; 
	    Node *st;           
    int n;                 int m;           
    int max_size;       
 
 
    
    void nextint(int &x){
      register int c = gc();
      x = 0;
      for(;(c<48 || c>57);c = gc());
      for(;c>47 && c<58;c = gc()){
        x = (x<<1) + (x<<3) + c - 48;
      }
    }
 
    
    void start(Node &a){
      a.sum = 0;
      a.wR[0] = 0;
      a.wR[1] = 0;
      a.wR[2] = 0;
    }
 
    
    int mid(int s, int e){  
      return s + (e -s)/2;  
    }
 
 
    
    Node merge(Node left, Node right) {
      Node res;
      start(res);
      res.sum = (left.sum + right.sum) % 3;
      for (int i = 0; i < 3; i++) {
        res.wR[i] += left.wR[i];
        res.wR[(i + left.sum) % 3] += right.wR[i];
      }
      return res;
    }
 
 
    
    void update(int index, int left, int right, int pos, int newValue){
      start(st[index]);
      if(left == right){ 
        st[index].sum = newValue%3;
        st[index].wR[st[index].sum] = 1;
      } 
      else{
        int m = (left + right) / 2;
        if (pos <= m)
          update(index * 2 + 1, left, m, pos, newValue);
        else
          update(index * 2 + 2, m + 1, right, pos, newValue);
        st[index] = merge(st[index * 2 + 1], st[index * 2 + 2]);
      }
    }
 
 
    
    Node gcn(int ss, int se, int qs, int qe, int index){
      if (qs <= ss && qe >= se)
        return st[index];
      if (se < qs || ss > qe){
        Node temp;
        start(temp);
        return temp;
      }
      int m = mid(ss, se);
      Node left = gcn(ss, m, qs, qe, 2*index+1);
      Node right = gcn(m+1, se, qs, qe, 2*index+2);
      Node result;
      start(result);
      result = merge(left, right);
      return result;
    }
 
 
   
    Node util(int ss, int se, int si){
      start(st[si]);
      if(ss == se){
        st[si].sum = a[ss]%3;
        st[si].wR[st[si].sum] = 1;
        return st[si];
      }
      int m = mid(ss, se);
      st[si] = merge(util(ss, m, si*2+1), util(m+1, se, si*2+2));
      return st[si];
    }
 
 
   
    void build(){
      int x = (int)(ceil(log2(n)));
      max_size = 2*(int)pow(2, x) - 1;
      st = new Node[max_size];
      util(0, n-1, 0);
    }
 
 
   
    long long ans(Node node){
      long long res = 0, curr = 0;
      for(int i = 0; i < 3; i++){
        curr = node.wR[i];
        if (i == 0)
          curr++;
        res += curr * (curr - 1) / 2;
      }
      return res;
    }
 
 
    int main(){
      int t,x,y;
      nextint(n); // size of input array(string)
      nextint(m); // no. of queries to process
 
      for(int i = 0; i<n; ++i)
      {
      	char ch;
      	cin>>ch;
      	a[i]=ch-'0';
      }
      
 
      
      build();
 
      
      while(m--){
        nextint(t); // denotes type of query
        nextint(x); // other two parameters for query
        nextint(y); 
    	x--;
        if(t == 1) 
          update(0, 0, n-1, x, y);
 
        else // make a query for range x to y both inclusive
          printf("%lld\n", ans(gcn(0, n-1, x,--y, 0)));
      }
      return 0;
    }
