#include<stdio.h>
inline void fast_read(int *number){

	*number=0;
	 char currentChar=getchar_unlocked();
            //Extract the front character from Keyboard buffer

	while(currentChar<'0'||currentChar>'9')	//Skips any non-digit Character
	    currentChar=getchar_unlocked();

	while(currentChar>='0'&&currentChar<='9'){

   		*number=(*number)*10+currentChar-'0';
		currentChar=getchar_unlocked();

	}

}




int main(){
	int i,b=1,a[b],c=0;

	for(i=0;i<b;i++){
		fast_read(&a[i]);
		if(c==0)
		printf("%d",a[i]);

		if(a[i]==42){
			c=1;
		}

		b++;
	}

	return 0;


}




