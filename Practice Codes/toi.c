#include<stdio.h>
void toi(int,char,char,char);
int main()
{
	int disks;
	printf("Enter the numbers of disks\n");
    scanf("%d",&disks);
    toi(disks,'A','B','C');
 	return 0;
}

void toi(int d,char source,char aux,char destination)
{
	if(d==1)
	printf("move disk 1 from %c to %c\n",source,destination);
	else{
	toi(d-1,source,destination,aux);
	printf("move disk %d from %c to %c\n",d,source,destination);
	toi(d-1,aux,source,destination);	
		
	}
}
