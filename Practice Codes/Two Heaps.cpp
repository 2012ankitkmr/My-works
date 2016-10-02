#include <iostream>
#include <vector>
#include <set>
#define MAXN 201

using namespace std;

vector<int> B[MAXN];
int G[MAXN];
int A[2][101];
int n;

int main() {
  cin >> n;
  n <<= 1;
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    B[x].push_back(i);
  }
  int id = 0;
  //twos
  for (int i = 10; i < 100; ++i) {
    if (B[i].size() > 1)
      for (int j = 0; j < 2; ++j) {
        G[B[i][j]] = (id&1)+1;
        A[id&1][id>>1] = i;
        id++;
      }
  }
  //ones
  for (int i = 10; i < 100; ++i) {
    if (B[i].size() == 1) {
      G[B[i][0]] = (id&1)+1;
      A[id&1][id>>1] = i;
      id++;
    }
  }
  //rest
  for (int i = 10; i < 100; ++i) {
    for (int j = 2; j < B[i].size(); ++j) {
      G[B[i][j]] = (id&1)+1;
      A[id&1][id>>1] = i;
      id++;
    }
  }
  set<int> S;
  n >>= 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      S.insert(A[0][i]*100+A[1][j]);
  cout << S.size() << endl;
  cout << G[0];
  n <<= 1;
  for (int i = 1; i < n; ++i)
    cout << " " << G[i];
  cout << endl;
}
