#include <stdio.h>

#include <string.h>

#define M 1000011



char str[M];



long long C[6][M], d[6][6][M];


int hashmap(char C) {

	switch(C) {

	case 'c' : return 1;

	case 'h' : return 2;

		case 'e' : return 3;

	case 'f' : return 4;

	default : return 0;
	}

}
 
int main() {
	int n, l, q, L, r, I, J, K;
	char AT[5], BT[5], a, b;
 
	scanf("%s", str);

	l = strlen(str);

	C[1][0] = C[2][0] = C[3][0] = C[4][0] = 0;

C[hashmap(str[0])][0]++;



	for(K=1; K<l; K++) {
	C[1][K] = C[1][K-1];
	C[2][K] = C[2][K-1];
	C[3][K] = C[3][K-1];
	C[4][K] = C[4][K-1];
	C[hashmap(str[K])][K]++;

	}

 
	for(K=1; K<5; K++) {
for(J=1; J<5; J++) {

		if(K == J)
				continue;

		d[K][J][0] = 0;

	for(I=1; I<l; I++) {

			d[K][J][I] = d[K][J][I-1];

		if(hashmap(str[I]) == J)

				d[K][J][I] += C[K][I];

		}

		}

}
scanf("%d", &q);

	for(K=0; K<q; K++) {
		scanf("%s%s%d%d", AT, BT, &L, &r);

		a = AT[0];
b = BT[0];

		

		if(L == 1)

			printf("%d\n", d[hashmap(a)][hashmap(b)][r-1]);
	else

		printf("%lld\n", d[hashmap(a)][hashmap(b)][r-1] - d[hashmap(a)][hashmap(b)][L-2]

	- C[hashmap(a)][L-2]*(C[hashmap(b)][r-1]-C[hashmap(b)][L-2]));
	}


	return 0;

}


