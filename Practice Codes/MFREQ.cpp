 #include<bits/stdc++.h>
 using namespace std;
 #define pb push_back
 struct interval
 {
 	int cnt,ele;
 	 
 	bool operator < (const interval &a) const
 	{
 		return cnt<a.cnt;
 	}
 }temp,temp1,temp2,temp3;
 vector<int>x,y;
 vector<interval>nod;
 int a[100005];
 interval tree[400005];
 
 int max3(interval a,interval b,interval c,int k)
 {
 	interval t,ans;
 	if(a.cnt>b.cnt)
 	t = a;
 	else
 	t = b;
 	
 	if(t.cnt>c.cnt)
 	ans = t;
 	else
 	ans = c;
 	
 	if(ans.cnt>=k)
 	return ans.ele;
 	else
 	return -1;
 }
 
 int binarysearch1(vector<int>v,int lo,int hi,int val)
 {
   int mid;    
 
  if(val <= v[lo])
    return lo; 
  if(val > v[hi])
    return -1;  
 
  mid = (lo + hi)/2;  /* low + (high - low)/2 */
 
  if(v[mid] == val)
    return mid;
  else if(v[mid] < val)
  {
    if(mid + 1 <= hi && val <= v[mid+1])
      return mid + 1;
    else
      return binarysearch1(v, mid+1, hi, val);
  }
 
  else
  {
    if(mid - 1 >= lo && val > v[mid-1])
      return mid;
    else    
      return binarysearch1(v, lo, mid - 1, val);
  }
	
 	
 }

int binarysearch2(vector<int>v,int lo,int hi,int val)
 {
 if(hi>=lo)
 	{
 		int mid = lo+(hi-lo)/2;
 	//	printf("t=%d %d %d\n",lo,hi,mid);
 		if(mid!=hi)
 		{
 			if((val>=v[mid])&&(val<v[mid+1]))
 			return mid;
 			else if(v[mid]>val)
 			return binarysearch2(v,lo,mid,val);
 			else
			return binarysearch2(v,mid+1,hi,val); 	
 		}
 		else
 		return hi;
 	}
 	return -1;
 	

}


int getmid(int a,int b)
{
	return a+(b-a)/2;
}

interval make_tree(int node,vector<interval>v,interval tr[],int ss,int se)
{
	if(ss==se)
	{
		tree[node]=v[ss];
		return tree[node];
	}
	int mid = getmid(ss,se);
	
	tree[node] = max(make_tree(2*node,v,tr,ss,mid),make_tree(2*node+1,v,tr,mid+1,se));
	return tree[node];
} 
 
interval getmax(int node,interval tr[],int ss,int se,int qs,int qe)
{
	temp.cnt = INT_MIN;
	temp.ele = INT_MIN;
	if(se<qs||ss>qe)
	return temp;
	
	if(qs<=ss&&qe>=se)
	return tree[node];
	
	int mid = getmid(ss,se);
	return max(getmax(2*node,tr,ss,mid,qs,qe),getmax(2*node+1,tr,mid+1,se,qs,qe));
}
 
 int main()
 {
// freopen("in.txt","r+",stdin);
 	int n,m,l,r,k,lptr,rptr,m1,m3;
 	
 	cin>>n>>m;
 	for(int i = 0 ; i < n ; i++)
 	scanf("%d",&a[i]);
 	
 	for(int i = 0 ; i < n ; i++)
 	{
 		if((i==0)||(a[i]!=a[i-1]))
 		{
 			x.pb(i);
 			if(i!=0)
 			{
 				y.pb(i-1);
 				nod.pb(temp);
 			}
 			temp.cnt = 1;
 			temp.ele =a[i];
 		}
 		else
 		temp.cnt++;
 	}
 	y.pb(n-1);
 	nod.pb(temp);
// 	for(int i=0;i<y.size();i++)
//	printf("%d %d    %d %d\n",x[i],y[i],nod[i].cnt,nod[i].ele);
 	temp = make_tree(1,nod,tree,0,nod.size()-1);
//for(int i=0;i<9;i++)
//printf("(%d,%d) ",tree[i].cnt,tree[i].ele);

 	for(int i = 0 ; i < m ; i++)
 	{
 		scanf("%d%d%d",&l,&r,&k);
 		
 		l--;
 		r--;
 		lptr = binarysearch1(x,0,x.size()-1,l);
 		rptr = binarysearch2(y,0,y.size()-1,r);
 		//printf("%d %d\n",lptr,rptr);
 	
	 	temp1.cnt = INT_MIN,temp3.cnt = INT_MIN;
 
    
 		if(lptr>0)
 		{
 			if(y[lptr-1]>=l)
 			{
 			m1 =  y[lptr-1] - l + 1;
 		    temp1.ele = nod[lptr-1].ele;
 		    temp1.cnt = m1;
			 }
	    }
	
		temp2 = getmax(1,tree,0,nod.size()-1,lptr,rptr);
	//	printf("%d %d\n",temp2.ele,temp2.cnt);
 
	    if(rptr<(nod.size()-1))
	    {
	    	if(x[rptr<=r])
	    	{
	    		m3 = (r - x[rptr+1] + 1);
	    	temp3.ele = nod[rptr+1].ele;
 		    temp3.cnt = m3;
	    	}
	    	
	    }
	    
	printf("%d\n",max3(temp1,temp2,temp3,k));
 	}
 	
 	return 0;
 }
