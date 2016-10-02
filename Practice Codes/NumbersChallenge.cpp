
static const int m=100000*20+1;
class NumbersChallenge {
public:
    int MinNumber(vector <int>);
};

int NumbersChallenge::MinNumber(vector <int> S) 
{
 bool pos[m]; 
 fill(pos,pos+m,false); 
 int i,j,p;
 vector<int> v; 
 pos[S[0]]=true;       // initialising
 v.push_back(S[0]);    
 for(i=1;i<S.size();i++)
 {  p=v.size(); 
    for(j=0;j<p;j++) 
    { if(pos[v[j]+S[i]]==false) 
        { pos[v[j]+S[i]]=true; v.push_back(v[j]+S[i]); }  
    }
   if(pos[S[i]]==false) 
   { v.push_back(S[i]); pos[S[i]]=true; }
 }    
 p=1; while(pos[p]) p++; return p;
}
