#include<stdio.h>
int l;
  int next_int()
{
        int n = 0;
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
 
  void swap(int *a,int *b)  

 {  

     *a = *a + *b; 
     *b = *a - *b; 
    *a = *a - *b;  
 } 
    
 void minHeapify(int a[],int size,int i)  
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
		    

 void buildMinHeap( int a[], int size) { 

     for( int i=size/2;i>=0;i--)  

         minHeapify(a,size,i);  
          

 } 
  
  int kthLargest( int a[], int size, int k)  

 { 
    int minHeap[k];  
    int i; 

    for(i=0;i<k;i++)  
         minHeap[i] = a[l+i]; 

    buildMinHeap(minHeap,k);  

     for(i=k;i<size;i++)  

     { 
         if(a[l+i]<minHeap[0])  
         {  

            minHeap[0]=a[l+i];  
            minHeapify(minHeap,k,0);  

         }  

    } 

    return minHeap[0];  

 } 
    

 
 int main()
{ int b;
	 int n,m,r,x,i,d,y;
     int a[500005];
	n=0;
	a[1]=0;
	for(m=next_int()/*scanf("%d",&m)*/;m--;)
	{
		//scanf("%d",&b);
		b=next_int();
		switch(b)
		{
			case 0: x=next_int();
			//scanf("%d",&x);
			        a[++n]=x;
			        break;
			case 1: l=next_int();
			        r=next_int();
			        x=next_int();
			       // scanf("%d%d%d",&l,&r,&x);
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
			        	printf("%d\n",y);
			        	break;
			case 2: x=next_int();
			        //scanf("%d",&x);
					n=n-x;
										
			        break;
			case 3: l=next_int();
			r=next_int();
			x=next_int();
			//scanf("%d%d%d",&l,&r,&x);
			        d=0;
					for(i=l;i<=r;i++)
			        {
			        	if(a[i]<=x)
			        	d++;
			        }
			        printf("%d\n",d);
					break;
			case 4:l=next_int();                         
			r=next_int();
			x=next_int();
//scanf("%d%d%d",&l,&r,&x);			    
		
			
			printf("%d\n",kthLargest(a,r-l+1,x)); 
					  break;       
	     }
	}
	return 0;
}
