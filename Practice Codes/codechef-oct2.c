#include<stdio.h>

int main(){
 long unsigned int j,t,i,a;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&a);
		long signed int d[a],s=0,k=0,flag,p;
		for(j=0;j<a;j++)
		scanf("%d",&d[j]);
		long signed int n[a],y,z[a],x,pos[a],q[a];
		y=0;
		for(j=0;j<a;j++)
		{z[j]=0;
		pos[j]=0;
	}
		for(j=0;j<a;j++){

			if(d[j]<0){
			n[k]=d[j];
			pos[k]=j;
			k++;
			}
			}
			z[y]=0;x=0;
			for(j=0;j<a;j++){
			if(d[j]>0){
				z[y]=d[j]+z[y];
				printf("z=%d&y=%d\n",z[y],y);
		}
		else
			{if(pos[j]!=j){
			y++;
			z[y]=0;
			}
		    }
			}
		p=0;y=0;
		q[y]=n[0]*(-1);
	for(j=0;j<a;j++){
		flag=pos[p]-j;
		if(flag<0){
			flag=flag*(-1);
			if(p<(k-1))
			p++;
		}
		if(d[j]>0){
			s=s+flag*d[j];
			printf("s in 1st block%d\nn[y]=%d\nz[y]=%d\n",s,n[y],z[y]);
			if(z[y]>n[y]*(-1)){

         flag=pos[y+1]-pos[y];
           if(q[y]>z[y])
			s=s+(flag)*(d[j]-n[y]*(-1));
			printf("s in 2nd block%d\n",s);
			//if(flag<=1)removed because of n[y] non increament
		y++;
		q[y]=q[y-1]+n[y]*(-1);
		p++;
	}
	}
		printf("pos[%d]=%d\ns=%d\n\n",p,pos[p],s);
	}

	printf("ans is %d\n",s);
	}
	return 0;
}
