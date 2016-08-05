#include<bits/stdc++.h>
using namespace std;
#define rev(st) reverse(st.begin(),st.end())
#define toUp(st) transform(st.begin(), st.end(),st.begin(), ::toupper);
#define toLo(st) transform(st.begin(), st.end(),st.begin(), ::tolower);
#define app_a(st) st.append("a");




map<string,int>predef_map;
map<string,int>userdef;

void assign_functions()
{
	String fun("reverse");
	predef_map[fun]=1;
	fun.assign("toupper");
	predef_map[fun]=2;
	fun.assign("tolower");
	predef_map[fun]=3;
	fun.assign("append_a");
	predef_map[fun]=4;
}


int func_count;

vector<queue<string> > function_sequence; 

vector<string>main_args;


int main()
{
func_count = 0;	
	assign_functions();
	
	string inputline;
   
    char *pch;
    
	while(1)
	{
		 vector<string>linetoken;
  
		getline(cin,inputline);
		if(inputline.compare("")==0)
		break;

	char *str;
	str = strdup(inputline.c_str());

    pch = strtok (str," ");
    
    
    while (pch != NULL)
   {
     string s(pch);
     linetoken.push_back(s);
   
      printf ("%s\n",pch);
      pch = strtok (NULL, " ");
    }
    
    if(line_token[0].compare("define")==0)
    {
    	queue<string> func_q;
    	userdef[line_token[1]] = ++func_count;
    	
    	while(1)
    	{
    	getline(cin,inputline);
		if(inputline.compare("end")==0)
		break;
		
		
		vector<string>linetoken1;
		str = strdup(inputline.c_str());
        pch = strtok (str," ");
         while (pch != NULL)
	     {
         string s(pch);
         linetoken1.push_back(s);
         printf ("%s\n",pch);
         pch = strtok (NULL, " ");
          }
          
          
          stack<string>funcstack;
          for(int i = 0;i<linetoken1.size()-1;i++)
          {
          	funcstack.push(linetoken1[i]);
          }
          
		  
		  while(!funcstack.isempty())
          {
           string out = funcstack.top();
          func_q.push(out);
		  funcstack.pop();	
          }
    	}
    	function_sequence.push_back(func_q);
    	
    }
    
    if(line_token[0].compare("print")==0)
    {
    	main_args.push_back(inputline);   	
    }
    
}

for(int i = 0 ; i < main_args.size() ; i++ )
{
	
	
	
	
	
}
	
	

	return 0;
}
