#include<bits/stdc++.h>
#define MAX 20005
#define pc putchar_unlocked
 
using namespace std;
 
typedef long long int lli;
 
void writeFast(lli Number){
	
	if(Number<0){pc('-');Number=-Number;}
	if(Number==0){	pc('0'); pc('\n'); return; }
	lli reversedNumber=0,count=0;
	while(Number%10==0){  count++; Number/=10;	}
	while(Number){ reversedNumber=reversedNumber*10+Number%10; Number/=10;}   
	while(reversedNumber){	pc(reversedNumber%10+'0'); reversedNumber/=10;	}
	while(count--) pc('0');
	pc('\n');
	
}   
 
 void fast_read(int *Input){
*Input=0;
int Negative=0;
register char CurrentChar=0;
while((CurrentChar<'0'||CurrentChar>'9')&&CurrentChar!='-')
CurrentChar=getchar_unlocked();
if(CurrentChar=='-'){
Negative=1;
CurrentChar=getchar_unlocked();
}
while(CurrentChar>='0'&&CurrentChar<='9'){
(*Input)= (*Input)*10 + CurrentChar-'0';
CurrentChar=getchar_unlocked();
}
if(Negative)
*Input=-*Input;
} 
 
struct Query{
	
	int l,r,idx;
	
	Query(){
	}
	
	Query(int l,int r,int idx){
		
		this->l=l;
		this->r=r;
		this->idx=idx;
		
	}
	
};
 
Query offline[MAX];
 
int size,Max;
 
bool comp(const struct Query &lhs,const struct Query &rhs){
	
	if(lhs.l/size!=rhs.l/size) return lhs.l/size<rhs.l/size;//sort by block
	else return lhs.r<rhs.r;	
	
}
 
int Tree[4*MAX];
int arr[MAX],Copy[MAX];
lli inversions=0,answerarr[MAX];;
std::map<int,int> Hash;//for co-ordinate compresseion
 
void update(int ,int ,int ,int ,int ,int );
int query(int ,int ,int ,int ,int );
 
 
inline void add(int element,int type){
	
//	cout<<"\nActual element is "<<element;
//	element=Hash[element];
	
	if(type==1)//we are coming from right
	{
	inversions+=(lli )query(0,0,Max-1,element+1,Max-1);
  ///  cout<<"\nWe added "<<query(0,0,MAX-1,element+1,MAX-1)<<" number of inversions"<<" and compressed value is  "<<element;
	
	}
	else{ 
	
	inversions+=(lli )query(0,0,Max-1,0,element-1);
	//cout<<"\nWe added "<<query(0,0,MAX-1,0,element-1)<<" number of inversions"<<" and compressed value is  "<<element;
    
	
	}
	
	update(0,0,Max-1,element,element,1);
	
}
 
inline void remove(int element,int type){
	
//	element=Hash[element];
	
	if(type==0)//removing from left...........so we need to find how many are smaller
	inversions-=(lli )query(0,0,Max-1,0,element-1);
	
	else inversions-=(lli )query(0,0,Max-1,element+1,Max-1);
	
	update(0,0,Max-1,element,element,-1);
	
}
 
int main(void){
	
	
	int totalElements,i,queries,start,end,currentL=0,currentR=0,count=1;
	
	scanf("%d",&totalElements);
	//,&queries);
         
 	for(i=0;i<totalElements;i++){
	
      fast_read(&arr[i]);
	  Copy[i]=arr[i];
      
	}
	
	sort(Copy,Copy+totalElements);
	
	//coordinate compression
	for(i=0;i<totalElements;i++)	
		if(Hash.find(Copy[i])==Hash.end()) 
		  Hash[Copy[i]]=count++;
	
	scanf("%d",&queries);	
	size=142;			
	for(i=0;i<queries;i++){
		
		fast_read(&start);
		fast_read(&end);
		offline[i]=(Query(start-1,end-1,i));
			
	}
			
    sort(offline,offline+queries,comp);
    
    
    for(i=0;i<totalElements;i++)
      arr[i]=Hash[arr[i]];
    
    Max=count+10;
    
	i=0; 
    while(queries--){
    	
    	start=offline[i].l;end=offline[i].r;
    	
    	//Solve Slowly here
    	    	
    	while(start>currentL){//removal required
    		
    		remove(arr[currentL],0);//while decrementing the number of inversions we need to decrease total number of
    		//numbers which are greater than this number
    		currentL++;
    		
		}
    	    		
    	while(currentL>start){//addition required
    		
    		add(arr[currentL-1],0);
    		currentL--;
    		
		}
				    	
    	while(end+1<currentR){//removal required
    		
    		remove(arr[currentR-1],1);
    		currentR--;
    		
		}
				
		while(currentR<=end){//addition required
			
			add(arr[currentR],1);
			currentR++;
			
		}
    	    	
    	//Slow Solver ends here
    	answerarr[offline[i].idx]=inversions;   	
    	i++;
    
       	
	}		
	
	queries=i;
	for(i=0;i<queries;i++)
	  writeFast(answerarr[i]);
	
	return 0;
	
}       
 
void update(int idx,int assStart,int assEnd,int s,int e,int val){
	
	if(assStart>assEnd||assStart>e||s>assEnd)//out of range
	  return;
	
	if(assStart>=s&&assEnd<=e){
		
		Tree[idx]+=(val);
		//cout<<"\nAFter update the occurence of "<<assStart<<" is "<<Tree[idx].ans;
		return;
		
	}
	
	int mid=(assStart+assEnd)>>1;
	
	update(2*idx+1,assStart,mid,s,e,val);
	update(2*idx+2,mid+1,assEnd,s,e,val);
	
	Tree[idx]=(Tree[2*idx+1]+Tree[2*idx+2]);
	
}
 
int query(int idx,int assStart,int assEnd,int s,int e){
	
	if(assStart>assEnd||assStart>e||s>assEnd) return 0;//out of range
	
	if(assStart>=s&&assEnd<=e) return Tree[idx];
	
	int mid=(assStart+assEnd)>>1;
	
	return query(2*idx+1,assStart,mid,s,e)+query(2*idx+2,mid+1,assEnd,s,e);
	
} 
