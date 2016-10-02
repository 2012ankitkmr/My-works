#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
struct suffix
{
    int index;  
    int rank[2];
};

int LCP_LR[4*MAXN];

 
int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
           (a.rank[0] < b.rank[0] ?1: 0);
}
 
vector<int> buildSuffixArray(string txt, int n)
{
    struct suffix suffixes[n];
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }
 
    sort(suffixes, suffixes+n, cmp);
 
    int ind[n];
    for (int k = 4; k < 2*n; k = k*2)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        for (int i = 1; i < n; i++)
        {
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else 
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: -1;
        }
 
        sort(suffixes, suffixes+n, cmp);
    }
 
    vector<int>suffixArr;
    for (int i = 0; i < n; i++)
        suffixArr.push_back(suffixes[i].index);
 
    return  suffixArr;
}
 
vector<int> kasai(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();
 
    vector<int> lcp(n, 0);
 
    vector<int> invSuff(n, 0);
 
    for (int i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;
 
    int k = 0;
 
    for (int i=0; i<n; i++)
    {
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
 
        int j = suffixArr[invSuff[i]+1];
 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
 
        lcp[invSuff[i]] = k; 
 
        if (k>0)
            k--;
    }
 
    return lcp;
}
 
void printArr(vector<int>arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void search(char *pat, char *txt, vector<int> Arr, int n)
{
    int m = strlen(pat);  
 
    int l = 0, r = n-1;  
    while (l <= r)
    {
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+Arr[mid], m);
 
        if (res == 0)
        {
            cout << "Pattern found at index " << Arr[mid];
            return;
        }
 
        if (res < 0) r = mid - 1;
 
        else l = mid + 1;
    }
 
    cout << "Pattern not found";
}

pair<int,int> Mstrncmp(char *s1,char *s2,int len,int st)
{
	
	// first index returns if 1 is lexicographically equal or less or greater than 2
	// second index sends number of equal indexes from beginning
int lenm = strlen(s2);
	pair<int,int>ans;
	ans.first =0,ans.second =0;
	for(int i= st;i<min(len,lenm);i++)
	{
		if(s1[i]>s2[i])
        {
		ans.first =1;
		return ans;
        }
		else if(s1[i]==s2[i])
		{
			ans.second++;
		}
		else
		{
		ans.first =-1;
		return ans;
		
		}
	}
	return ans;
}

void searchwithlcp(char *pat, char *txt, vector<int> suffArr, int n)
{
    int m = strlen(pat);  
 
    int l = 0, r = n-1;  
    int k=0 ,ind=1;
int mid =0;
 int lcpmm;
 int fl=0;
while(l<=r)
{
	    mid = l + (r - l)/2;
		pair<int,int> res = Mstrncmp(pat, txt+suffArr[mid], m,k);

     	k = res.second;
	   
	   	int midm=mid+(r-mid)/2;
	   
	      lcpmm = LCP_LR[ind*2];
		
		 if(res.first==0&&k==m)
		 {
		     cout << "Pattern found at index " << suffArr[mid];
            return;	
		 }
		 if(k<lcpmm)
		 {
		 	ind = ind*2+1;
		 l = mid;
		 }
		 if(k>lcpmm){
		 	ind = ind*2;
		 	r= mid;
		 }
	
}
    cout << "Pattern not found";
}
void buildLCP_LR(int index, int low, int high,vector<int>LCP)
{
    if(low == high)
    {
        LCP_LR[index] = LCP[low];
        return;
    }

    int mid = (low + high) / 2;

    buildLCP_LR(2*index, low, mid,LCP);
    buildLCP_LR(2*index+1, mid + 1, high,LCP);

    LCP_LR[index] = min(LCP_LR[2*index], LCP_LR[2*index + 1]);
}

 
int main()
{
    string str = "banana";
    
 
    vector<int>suffixArr = buildSuffixArray(str, str.length());
    int n = suffixArr.size();
 
    cout << "Suffix Array : \n";
    printArr(suffixArr, n);
 
    vector<int>lcp = kasai(str, suffixArr);
 
    cout << "\nLCP Array : \n";
    printArr(lcp, n);
     char pat[] = "nan"; 
     char txt[] = "banana";

    search(pat, txt, suffixArr, n);
    for(int i = 0;i<4*MAXN;i++)
    LCP_LR[i] =INT_MAX;
    
    buildLCP_LR(1,0,n-1,lcp);
    searchwithlcp(pat,txt,suffixArr,n);
    
    return 0;
}
