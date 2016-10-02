#include<bits/stdc++.h>
#define MAX 500005
 
using namespace std;
 
/**
Types of queries available :-
Type 1 :- Get total number of super numbers in range from L to R
Type 2 :- Change the number at ith index to Y  --Done
Type 3 :- Check if number formed by appending numbers from L to R to form a single number is a super number or not
Type 4 :- Find the index of kth super number in the current array
*/
 
/**
10 100
23 4 12312 7872955 12 4329 3242 123 3 10
*/
 
vector<int> primes;
inline int isGoodNumber(int mask){
	if(mask==0||(mask==(1<<4))) return 1;
	else return 0;	
}
 
int getMask(int number){
 
	if(number==0) return 1<<4;
 
	int product=1,temp=number;
	while(number){
		product*=number%10;
		number/=10;		
    }
 
	number=product;
	int i=0,correspondingBit,newMask=0;
	while(number>1&&i<primes.size()){
 
		int count=0;
		while(number%primes[i]==0){			
			number/=primes[i];
			count++;	
		}
 
		correspondingBit=3-i;
		if(count%2)	newMask|=(1<<correspondingBit);
 
		i++;
 
	}
 
	return newMask;
 
}
 
inline int getCombinedMask(int num1,int num2){
	if(num1==(1<<4)||num2==(1<<4)) return 1<<4;
	else return num1^num2;	
}
 
struct node{
 
	int mask,count;
	node(){
		mask=count=-1;		
	}
 
	node(int number){
		mask=getMask(number);
		count=isGoodNumber(mask);
	}
 
	node(int mask,int count){
		this->mask=mask;
		this->count=count;		
	}
 
	struct node merge(struct node lhs,struct node rhs){
		this->mask=getCombinedMask(lhs.mask,rhs.mask);
		this->count=lhs.count+rhs.count;	
	}
 
};
 
struct node Tree[4*MAX];
int arr[MAX],totalElements,queries,flag=0;
 
void makeTree(int ,int ,int );
void update(int ,int ,int ,int ,int ,int );
int getKthNumber(int );
struct node rangeQuery(int ,int ,int ,int ,int );
 
int main(void){
 
 freopen("in.txt","r",stdin);
//	freopen("C:\\Misc\\Data\\Love@first sight\\Data Structure and Algorithms\\AlgoGeek\\Solutions_\\segMentData5.txt","r",stdin);
 //   freopen("C:\\Misc\\Data\\Love@first sight\\Data Structure and Algorithms\\AlgoGeek\\Solutions_\\segMentOut5.txt","w",stdout);
 
	primes.push_back(2);primes.push_back(3);
	primes.push_back(5);primes.push_back(7);
 
	int i,l,r,queryType;
 
	cin>>totalElements>>queries;
	for(i=0;i<totalElements;i++)
	   scanf("%d",&arr[i]);
 
	struct node ans;
 
	makeTree(0,0,totalElements-1);
 
//	cout<<"\nTotal such numbers are "<<Tree[0].count<<"\n";
//	cout<<rangeQuery(0,0,totalElements-1,0,0).count<<endl;
	while(queries--){
 
		scanf("%d",&queryType);		
 
		switch(queryType) {
 
			case 1://get good numbers from l to r
 
			scanf("%d%d",&l,&r);
			ans=rangeQuery(0,0,totalElements-1,l,r);
			printf("%d\n",ans.count);				
			break;
 
			case 2: //update number at lth index with r
 
			scanf("%d%d",&l,&r);	
			update(0,0,totalElements-1,l,l,r);	
			break;
 
			case 3://check if number formed after concatinating from L to R is good number or not
 
			scanf("%d%d",&l,&r);	
		    ans=rangeQuery(0,0,totalElements-1,l,r);			    
			if(isGoodNumber(ans.mask)) printf("Yes\n");
			else printf("No\n");
 
			break;			
 
			case 4://get kth such number	
 
			scanf("%d",&l);
 
		    printf("%d\n",getKthNumber(l));
			break;
 
		}
 
		flag++;
 
	}
 
	return 0;
 
}
 
void makeTree(int idx,int start,int end){
 
	if(start==end){
 
		Tree[idx]=node(arr[start]);	
		return;
 
	}
 
	int mid=(start+end)/2;
	makeTree(2*idx+1,start,mid);
	makeTree(2*idx+2,mid+1,end);
 
	Tree[idx].merge(Tree[2*idx+1],Tree[2*idx+2]);	
 
}
 
void update(int idx,int assStart,int assEnd,int s,int e,int changeWith){
 
	if(assStart>assEnd||(assStart>e)||(s>assEnd))// out of range
	 return;
 
	if(assStart==assEnd){
		Tree[idx]=node(changeWith);
		return;	
	}
 
	int mid=(assStart+assEnd)/2;
 
	update(2*idx+1,assStart,mid,s,e,changeWith);
	update(2*idx+2,mid+1,assEnd,s,e,changeWith);
	Tree[idx].merge(Tree[2*idx+1],Tree[2*idx+2]);
 
}
 
struct node rangeQuery(int idx,int assStart,int assEnd,int s,int e){
 
	if(assStart>assEnd||(assStart>e)||(s>assEnd))// out of range
	 return node(-1,-1);
 
	if(assStart>=s&&assEnd<=e) return Tree[idx];
 
	struct node lhs,rhs,ans;
	int mid=(assStart+assEnd)/2;
 
	lhs=rangeQuery(2*idx+1,assStart,mid,s,e);
	rhs=rangeQuery(2*idx+2,mid+1,assEnd,s,e);
 
	if(lhs.count==-1) return rhs;
	if(rhs.count==-1) return lhs;
 
	ans.merge(lhs,rhs);
 
	return ans;
 
}
 
int getKthNumber(int k){//make sure that the case for no super number is handeled
 
    if(k>Tree[0].count) return -1;
 
	int backLog=0,assStart=0,assEnd=totalElements-1,mid,idx=0;	
	while(assStart!=assEnd){
 
		mid=(assStart+assEnd)/2;		
		if(backLog+Tree[2*idx+1].count<k){//time to move in right
			backLog+=Tree[2*idx+1].count;
			idx=2*idx+2;
			assStart=mid+1;
		}
 
		else{	
			idx=2*idx+1;
			assEnd=mid;
		}
 
	}
 
	return assStart;	
}
