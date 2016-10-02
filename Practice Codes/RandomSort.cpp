#include<bits/stdc++.h>
using namespace std;

map<vector<int>, double> dp;

class RandomSort {
public:
  double getExpected(vector <int> permutation) {
	double sum=0;
	int cnt=0;

	if(dp.count(permutation)) return dp[permutation];

	for(int i=0 ; i<permutation.size() ; i++){
		for(int j=i+1 ; j<permutation.size() ; j++){
			if(permutation[i] > permutation[j]){
				// swap
				int tmp = permutation[j];
				permutation[j] = permutation[i];
				permutation[i] = tmp;

				sum += getExpected(permutation);
				cnt++;

				tmp = permutation[j];
				permutation[j] = permutation[i];
				permutation[i] = tmp;
			}
		}
	}
	if(cnt) sum = sum/cnt+1;
//	printf("returning %lf after \n",sum);
//	for(int i=0;i<permutation.size();i++)
//	printf("%d ",permutation[i]);
//	printf("\n");
	return dp[permutation] = sum;

  }
};
/*
int main()
{
	RandomSort a;
	vector<int>p;
	p.push_back(1);
		p.push_back(3);
			p.push_back(4);	
			    p.push_back(2);
	
	printf("%lf\n",a.getExpected(p));
	
}*/
