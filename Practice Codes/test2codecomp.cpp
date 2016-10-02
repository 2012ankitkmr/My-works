#include<stdio.h>
 
long int next_int()
{
       long int n = 0;
        char c = getchar_unlocked();
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked(); 
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
        return n;
}
 
  void swap(int *a, int *b)  
 
 {  
 
     *a = *a + *b; 
     *b = *a - *b; 
    *a = *a - *b;  
 } 
    
 void minHeapify(int a[], int size, int i)  
 {  
     int l = 2*i;  
    int r = 2*i+1; 
     int smallest = i;  
   if(l<size && a[l]>a[smallest])  
         smallest = l; 
    if(r<size && a[r]>a[smallest])  
        smallest = r;  
     if(smallest!=i)  
	     {  
        swap(&a[i],&a[smallest]);  
        minHeapify(a,size,smallest);  
     }  
        } 
		    
 
 void buildMinHeap(int a[], int size) { 
 
     for(int i=size/2;i>=0;i--)  
 
         minHeapify(a,size,i);  
          
 
 } 
  
 int kthLargest(int a[], int size, int k)  
 
 { 
     int minHeap[k];  
    int i; 
 
    for(i=0;i<k;i++)  
         minHeap[i] = a[i]; 
 
    buildMinHeap(minHeap,k);  
 
     for(i=k;i<size;i++)  
 
     { 
         if(a[i]<minHeap[0])  
         {  
 
            minHeap[0]=a[i];  
            minHeapify(minHeap,k,0);  
 
         }  
 
    } 
 
    return minHeap[0];  
 
 } 
    
 
 
 int main()
{ int b;
	long int n,m,a[250005],l,r,x,i,d,y,max;
	int arr[250005];
	n=0;
	a[1]=0;
	max=0;
	for(m=next_int()/*scanf("%ld",&m)*/;m--;)
	{
		scanf("%d",&b);
		switch(b)
		{
			case 0: x=next_int();
			//scanf("%ld",&x);
			        a[++n]=x;
			        if(max<x)
			        max=x;
			        break;
			case 1: l=next_int();
			        r=next_int();
			        x=next_int();
			        //scanf("%ld%ld%ld",&l,&r,&x);
						d=0;
			        	y=a[l];
			        	for(i=l;i<=r;i++)
			        	{
			        		if(d<(a[i]^x))
			        		{
			        		//printf("d=%ld,a[i]^x=%ld,y=%ld\n",d,a[i]^x,y);
			        			d=a[i]^x;
			        			y=a[i];
			        		}
			        	}
			        	printf("%ld\n",y);
			        	break;
			case 2: x=next_int();
			        //scanf("%ld",&x);
					n=n-x;				
			        break;
			case 3: l=next_int();
			r=next_int();
			x=next_int();
			//scanf("%ld%ld%ld",&l,&r,&x);
			        d=0;
					for(i=l;i<=r;i++)
			        {
			        	if(a[i]<=x)
			        	d++;
			        }
			        printf("%ld\n",d);
					break;
			case 4: l=next_int();                         
			r=next_int();
			x=next_int();
//scanf("%ld%ld%ld",&l,&r,&x);			    
			for(i=0;i<=r-l+1;i++)
			arr[i]=a[i+l];
			
			printf("%d\n",kthLargest(arr,r-l+1,x)); 
					  break;       
	     }
	}
	return 0;
}
