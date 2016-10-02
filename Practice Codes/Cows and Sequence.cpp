#include<bits/stdc++.h>
using namespace std;


int main() {

long long n ;
cin>>n;
vector<long long > arr(n + 1 , 0);
vector<long long> sum(n + 1 , 0);

double avg;
long long type , a , x, k, last , size , diff ,total = 0;

size = 1;
last = 0; // index of the last number

for(long long  i = 0 ; i < n ; i ++)
{

cin>>type;
if(type == 1){
cin>>a>>x;
sum[a-1] += x;

total += (x*a);
avg = total/(double)size;

  printf("%lf\n",avg);
}


else if(type == 2) {
  cin >> k;
sum[size] = k;
  arr[size++] = k;

//  printf("total=%d\n", total );
total += k;
avg  = total/(double)size;
  printf("%lf\n", avg);
  last++;

}

else {

diff = sum[last] - arr[last];
sum[last-1]+= diff;
                              // lazy propagation
total -= sum[last];

arr[last] = 0;
sum[last] = 0;
size --;
last --;
avg = total/(double)size;
printf("%lf\n", avg );
}


}
  return 0;
}
