#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 1000000 + 10;
char num[MAXN];
int a, b, len;
int64 moda, modb;

inline int pow_mod(int n) {
  if(n == 0) return 1;
  int x = pow_mod(n/2);
  int64 ans = (int64)x * x % b;
  if(n%2 == 1) ans = ans * 10 % b;
  return (int)ans;
}

inline void init(void) {
  len = strlen(num);
  moda = 0;
  modb = 0;
  for(int i = 0; i < len; ++i)
    modb = (modb*10 + num[i] - '0')%b;
}

inline void update(int i) {
  moda = ((moda*(10%a))%a + (num[i]-'0')%a)%a;
  modb = (modb - ((((num[i]-'0')%b) * pow_mod(len-i-1))%b))%b;
}

int main(void) {
  while(scanf("%s", num) != EOF) {
    scanf("%d %d", &a, &b);
    getchar();
    int ans = 0;
    init();
    for(int i = 0; i < len - 1; ++i) {
      update(i);
      if(num[i+1] != '0' && moda == 0 &&  modb == 0) {
        ans = i+1; break;
      }
    }
    if(ans != 0) {
      printf("YES\n");
      for(int i = 0; i < ans; ++i)
        printf("%c", num[i]);
      printf("\n");
      puts(num+ans);
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
