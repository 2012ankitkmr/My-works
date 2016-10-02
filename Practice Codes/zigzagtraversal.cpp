#include<bits/stdc++.h>
using namespace std;

struct btreenode{
	int data;
	struct btreenode*left;
	struct btreenode*right;
};

struct btreenode* newnode(int data)
{
	struct btreenode*node = (struct btreenode*)malloc(sizeof(struct btreenode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
	
}

void printzigzag(struct btreenode*root)
{
	if(!root)
	return;
	stack<btreenode*>s;
	s.push(root);
	bool lefttoright = 1;

	while(!s.empty())
	{
		struct btreenode*temp = s.top();
		s.pop();
	    if(temp)
		{
		printf("%d ",temp->data);
		
		
		if(!lefttoright)
    	{
 		if(temp->left)
		s.push(temp->left);
		if(temp->right)
		s.push(temp->right);
        }
        
		else
        {
 		if(temp->right)
		s.push(temp->right);
		if(temp->left)
		s.push(temp->left);
	
        }
	
	    }
		else
		{
			if(!s.empty())
			s.push(NULL);	
			lefttoright=^1;		
		}
		
	}
	
}

int main()
{
	struct btreenode*root;
	root = newnode(1);
	root ->left = newnode(2);
	root ->right = newnode(3);
	root ->left->left = newnode(4);
	root ->left->right = newnode(5);
	root ->right->left = newnode(6);	
	root ->right->right = newnode(7);
	
	printzigzag(root);
	return 0;
}
