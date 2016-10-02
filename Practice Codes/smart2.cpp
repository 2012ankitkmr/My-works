#include <bits/stdc++.h>
using namespace std;

map<string,int>predef_map;
map<string,int>userdef;

int func_count;

vector<queue<string> > function_sequence; 

vector<string>main_args;


void assign_functions()
{
	//  assigns maps to predefs
	
	string fun("reverse");
	predef_map[fun]=1;
	fun.assign("toupper");
	predef_map[fun]=2;
	fun.assign("tolower");
	predef_map[fun]=3;
	fun.assign("append_a");
	predef_map[fun]=4;
	
}

string find_output(string param,int num_q,string args)
{
	//printf("Actions: ");
	///cout<<param<<endl;
    if(predef_map[param]==1)
	{
		reverse(args.begin(),args.end());
		return args;
	}
	 else if(predef_map[param]==2)
	 {
		 transform(args.begin(), args.end(),args.begin(), ::toupper);
		 return args;
	 }
	  else if(predef_map[param]==3)
	  {
		  transform(args.begin(), args.end(),args.begin(), ::tolower);
		  return args;
	  }
	  else if(predef_map[param]==4)
	  {
		return args.append("a");
	  }
	else
	{
		
		string ans(args);
		
		queue<string> temp(function_sequence[num_q]);
		while(!temp.empty())
		{
			string sfun = temp.front();
				temp.pop();
			if(predef_map[sfun])
         ans = 	find_output(sfun,-1,ans);
	   	else
          ans =	find_output(sfun,userdef[sfun]-1,ans);
		}	
return ans;
	}	
}

int main() {
	  func_count = 0;	
	assign_functions();
	
	string inputline;
   
    char *pch;
	char *str;
	
while(1)
	{
	vector<string>line_token;
	getline(cin,inputline);
	if(inputline.compare("")==0)
		break;
	
	str = strdup(inputline.c_str());
	 pch = strtok (str," ");
	  while (pch != NULL)
   {
		   string s(pch);
     line_token.push_back(s);
		//   printf ("%s\n",pch);
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
		{
			break;
		}
		
		vector<string>linetoken1;
		str = strdup(inputline.c_str());
		 pch = strtok (str," ");
		while(pch!=NULL)
		{
		    string s(pch);
	    	linetoken1.push_back(s);
		//		printf ("%s\n",pch);
		   	pch = strtok (NULL, " ");
			
		}
		stack<string>funcstack;
		for(int i = 0;i<linetoken1.size()-1;i++)
	     {
          	funcstack.push(linetoken1[i]);
          }
		  while(!funcstack.empty())
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

	
		vector<string>linetoken1;
	str = strdup(main_args[i].c_str());
        pch = strtok (str," ");
	  while (pch != NULL)
	     {
       string s(pch);
		  linetoken1.push_back(s);
		//  printf("%s\n",pch);
		   pch = strtok (NULL, " ");
          }
		  
	 string arg = linetoken1[linetoken1.size()-1];
	arg.erase( remove( arg.begin(), arg.end(),'"') );
	arg.erase(remove(arg.begin(),arg.end(),'"'));
	string output_ans(arg);
	stack<string>funcstack;
	 for(int i = 1;i<linetoken1.size()-1;i++)
		 {
          	funcstack.push(linetoken1[i]);
		 if(!(userdef[linetoken1[i]]||predef_map[linetoken1[i]]))
		 {output_ans.assign("ERROR");
		while(!funcstack.empty())
			funcstack.pop();
			
		  break;
		 }
		 }
	
	
	   while(!funcstack.empty())
          {
	
          	string currentfun = funcstack.top();
          	funcstack.pop();
	
		   if(predef_map[currentfun])
            output_ans=find_output(currentfun,-1,output_ans);
		   else if(userdef[currentfun])
          	output_ans=find_output(currentfun,userdef[currentfun]-1,output_ans);
		   else
		   {
           output_ans.assign("ERROR");
		   }
		    }
          cout<<output_ans<<endl;
	}
return  0;
}
