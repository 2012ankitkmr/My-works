#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
 
 /*
                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r

*/ 
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    bool isLeaf;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 
        pNode->isLeaf = false;
 
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}
 
void insert(struct TrieNode *root, const char *key)
{
    int i;
    int length = strlen(key);
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (i = 0; i < length; i++)
    {
        index = CHAR_TO_INDEX(key[i]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
}
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isLeaf);
}

struct trieheap_link{
	int data;
	int val;
};
struct heap{

int heaptype;
int capacity;
int heapcount;
trieheap_link *array;

};

struct heap* createheap(int capacity,int heaptype)
{
	struct heap* H =(struct heap*)malloc(sizeof(struct heap));
	if(H!=NULL)
	{
		H->heaptype = heaptype;
		H->capacity = capacity;
		H->heapcount = 0;
		H->array = (struct trieheap_link*)malloc(sizeof(struct trieheap_link)*H->capacity);				
		
	}
return H;	
}
int parent(struct heap*h,int i)
{
	if(i<=0||i>=h->count)
	return -1;
	return (i-1)/2;
}

int leftChild(struct heap*h,int i)
{
	int left = 2*i+1;
	if(left>=h->count)
	return -1;
	return left;
}
int rightChild(struct heap*h,int i)
{
	int right = 2*i+2;
	if(left>=h->count)
	return -1;
	return right;
}

int getMax(struct heap*h)
{
	if(h->count==0)
	return -1;
	return h->array[i].data;
}

void PercolateDown(struct heap*h,int i)
{
	int left,right,max,temp;
	
	left = leftChild(h,i);
	right = rightChild(h,i);
	
	if(left!=-1&&h->array[l].val)
	
	
}


int main()
{
    char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
 
 struct heap *heaproot = createheap(1000,1);
 
 
    struct TrieNode *root = getNode();
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);
 
 
    return 0;
}
