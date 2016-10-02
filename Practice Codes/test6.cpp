#include<stdio.h> 

  

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
    

    

int main() {  
   int a[] = {16,17,18,4,12,9,5,1};  

    int size = sizeof(a)/sizeof(a[0]);  

     int k = 5;  

    printf("%d ",kthLargest(a,size,k)); 
for(i=0;i<8;i++)
printf("%d",a[i]);


     return 0;  

 } 

