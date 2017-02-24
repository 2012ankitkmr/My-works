#include <bits/stdc++.h>
using namespace std;
#define ll long long 

typedef struct city {
  long long population;
  long long clinic_cnt;
  long long load;
} city;

int comp(const void * city1, const void *city2)
{

  city *mycity1 , *mycity2;
  mycity1 = (city *) city1;
  mycity2 = (city *) city2;

  return (mycity1->load - mycity2->load);
}

int find_ans(ll cities_cnt,ll clinic_cnt,ll arr[])
{
  long long  i;
  city cities[1024];


  for(i = 0;i < cities_cnt; i++)
  {
   cities[i].population=arr[i];
    cities[i].clinic_cnt = 1;
    
    cities[i].load = cities[i].population;
  }

  qsort(cities, cities_cnt, sizeof(city),comp);


  for (i = 0; i < (clinic_cnt - cities_cnt); i++)
  {
    cities[cities_cnt -1].clinic_cnt ++;
    cities[cities_cnt -1].load = cities[cities_cnt -1].population/cities[cities_cnt -1].clinic_cnt;
    if (cities[cities_cnt -1].population%cities[cities_cnt -1].clinic_cnt)
      cities[cities_cnt -1].load++;
    qsort(cities, cities_cnt, sizeof(city),comp);
  }

  return  cities[cities_cnt -1].load;
}


int main()
{
	ll n= 2,b=7,arr[]={200000,500000};
	cout<<find_ans(n,b,arr);
	return 0;
}
