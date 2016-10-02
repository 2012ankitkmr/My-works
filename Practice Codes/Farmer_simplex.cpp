#include<bits/stdc++.h>
using namespace std;

#define se second 
#define fi first 

double F,P,L,F1,F2,P1,P2,S1,S2;

double stringtonum(string st)
{
	double num= 0.0;
for(int it = 0 ; it < st.size() ; it++)	
{
num = 10.0*num + (st[it] - '0');	
}
return num;	
}

double min(double a,double b)
{
	return a>b?b:a;
}

set<pair<double,double> >points;




pair<double,double> getintersectionpoints(double a,double b,double c,double d,double e,double f)
{
	if(a/b==d/e)
	return make_pair(-1.0,-1.0);
	else
	return make_pair(((c*e - b*f)/(e*a - d*b)),((a*f - d*c)/(e*a - d*b)));
}


char *get_total_profit(char*input1)
//int main()
{

char *pch,*str = input1;

vector<string>line_token;
	 pch = strtok (str,",");
	  while (pch != NULL)
   {
		   string s(pch);
     line_token.push_back(s);
		//   printf ("%s\n",pch);
      pch = strtok (NULL, ",");
    }
//strtok
L = stringtonum(line_token[0]);
F = stringtonum(line_token[1]);
P = stringtonum(line_token[2]);
F1 = stringtonum(line_token[3]);
P1 = stringtonum(line_token[4]);
F2 = stringtonum(line_token[5]);
P2 = stringtonum(line_token[6]);
S1 = stringtonum(line_token[7]);
S2 = stringtonum(line_token[8]);

//scanswerf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&L,&F,&P,&F1,&P1,&F2,&P2,&S1,&S2);
 
pair<double,double>tp ,tp1,tp2;

tp.fi = min(L , min(F/F1 , P/P1 ));
tp.se = 0.0;
points.insert(tp);

tp.fi = 0.0;
tp.se = min(L , min(F/F2 , P/P2 ));
points.insert(tp);

//  line 1   &  line 2
tp = getintersectionpoints(F1,F2,F,P1,P2,P);
if((tp.fi>=0&&tp.se>=0)&&((tp.fi + tp.se)<=L))
{
	points.insert(tp);
}
else
{
	tp1 = getintersectionpoints(F1,F2,F,1,1,L);
	tp2 = getintersectionpoints(P1,P2,P,1,1,L);
if((tp.fi>=0&&tp.se>=0))
{
	if(tp1.fi>=0&&tp1.se>=0)
		points.insert(tp1);
		
	if(tp2.fi>=0&&tp2.se>=0)
		points.insert(tp2);
}
else
{
	if(F/F1>P/P1){
	if(tp2.fi>=0&&tp2.se>=0)
	points.insert(tp2);
	}
	else
	{
	if(tp1.fi>=0&&tp1.se>=0)
		points.insert(tp1);	
}
}
}
double maxZ = -1.0,x1,x2,Z;

set<pair<double,double> >::iterator it;
for(it = points.begin() ; it != points.end() ; it++)
{
	
	pair<double,double>pa = *it;
//	printf("%lf %lf\n",pa.first,pa.second);
	Z = pa.fi*S1 + pa.se*S2;
	if(Z == maxZ)
	{
		std::string str = "-1";
    char* inp1 = strdup(str.c_str());
    return  inp1;
	}
	else if(Z > maxZ)
	{
		maxZ = Z;
		x1 = pa.fi;
		x2 = pa.se;
	}
}
stringstream ans;
ans<<fixed<<setprecision(2)<<maxZ<<","<<x1<<","<<x2;
string stri(ans.str());

char* ank;
	ank = strdup(stri.c_str());
return ank;

}

