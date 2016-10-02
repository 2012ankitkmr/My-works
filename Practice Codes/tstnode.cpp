#include<bits/stdc++.h>
#include<string.h>
using namespace std;

struct tstnode{
	char data;
	int end_of_string;
	struct tstnode*left;
	struct tstnode*right;
	struct tstnode*eq;
};
struct tstnode*insert(struct tstnode*root,char*word,int data)
{

	if(root==NULL)
	{
		root=(struct tstnode*)malloc(sizeof(struct tstnode));
		root->data=*word;
		root->end_of_string=data;
		root->left=root->eq=root->right=NULL;
	}
	if(*word<root->data)
{//printf("l%c",*word);
	root->left=insert(root->left,word,data);
}
	else if(*word>root->data)
{//printf("r%c",*word);
	root->right=insert(root->right,word,data);
}
	else if(*word==root->data)
	{	
		if(*(word+1))
		root->eq=insert(root->eq,(word+1),data);
		else
		{
		root->end_of_string=data;
	}
	}
	return root;
}

int search(struct tstnode*root,char*word)
{
	if(root==NULL)
return 0;
	// printf("%c",root->data);
	if(*word<root->data)
	return search(root->left,word);
	else if(*word>root->data)
	return search(root->right,word);
	else{
	    if(root->end_of_string!=0&&*(word+1)=='\0')
	    {
   
		return root->end_of_string;
	}
		else
		return search(root->eq,(word+1));
	}
	
}
char word[56];
int i=0;
void display(struct tstnode*root)
{
	
	if(!root)
	return;

	display(root->left);
	word[i]=root->data;
	
	if(root->end_of_string!=0)
	{
		//printf("%d\n",i);
		word[i+1]='\0';
		printf("%c",word[i]);
	}
	i++;
	display(root->eq);
	i--;
	display(root->right);
}

int maxlength(struct tstnode*root)
{
	if(!root)
	return 0;
	int m= max(maxlength(root->left),maxlength(root->eq)+1);
	
	return (m,maxlength(root->right));
}


int main()
{
	char s[20]="ankit";

struct tstnode*root=(struct tstnode*)malloc(sizeof(struct tstnode));
//root->data='a';
//root->end_of_string=1;
struct tstnode*temp,*temp1=insert(root,s,1);
//printf("%c",root->eq->eq->eq->data);
char p[]="all";

struct tstnode*temp2=insert(root,p,2);
strcpy(p,"kumar");
temp2=insert(root,p,3);

strcpy(p,"iz");
temp2=insert(root,p,4);

strcpy(p,"well");
temp2=insert(root,p,5);
temp=root->right;
strcpy(p,"kumar");
printf("%d\n",search(root,p));
	display(root);
	return 0;
}
