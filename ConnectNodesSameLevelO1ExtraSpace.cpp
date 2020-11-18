
/*

Input Tree
       A
      / \
     B   C
    / \   \
   D   E   F

Output Tree
       A--->NULL
      / \
     B-->C-->NULL
    / \   \
   D-->E-->F-->NULL


*/


#include <bits/stdc++.h>
using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
    node *nextRight;  
      
    /* Constructor that allocates a new node with the  
    given data and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
        this->nextRight = NULL; 
    } 
};  

node* getnextright(node* p)
{
	node* tmp = p->nextRight;
	while(tmp!=NULL)
	{
		if(tmp->left)
		return tmp->left;
		if(tmp->right)
		return tmp->right;
		tmp=tmp->nextRight;
	}
	return NULL;
}

void connectRecur(node* p)
{
	if(!p)
	return;
	p->nextRight=NULL;
	while(p)
	{
		node*q = p;
		while(q)
		{
			if(q->left)
			{
				if(q->right)
				{
					q->left->nextRight=q->right;
				}
				else
				q->left->nextRight=getnextright(q);
			}
			if(q->right)
			q->right->nextRight=getnextright(q);
			q=q->nextRight;
		}
		
		if(p->left)
		p=p->left;
		else if(p->right)
		p=p->right;
		else
		p=p->nextRight;
	}
}

/* Driver code*/
int main()  
{  
  
    /* Constructed binary tree is  
            10  
            / \  
        8 2  
        /     \  
    3     90  
    */
    node *root = new node(10);  
    root->left = new node(8);  
    root->right = new node(2);  
    root->left->left = new node(3);  
    root->right->right     = new node(90);  
  
    // Populates nextRight pointer in all nodes  
    connectRecur(root);  
  
    // Let us check the values of nextRight pointers  
    cout << "Following are populated nextRight pointers in the tree"
        " (-1 is printed if there is no nextRight) \n";  
    cout << "nextRight of " << root->data << " is "
        << (root->nextRight? root->nextRight->data: -1) <<endl;  
    cout << "nextRight of " << root->left->data << " is "
        << (root->left->nextRight? root->left->nextRight->data: -1) << endl; 
    cout << "nextRight of " << root->right->data << " is "
        << (root->right->nextRight? root->right->nextRight->data: -1) << endl; 
    cout << "nextRight of " << root->left->left->data<< " is "
        << (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl; 
    cout << "nextRight of " << root->right->right->data << " is "
        << (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl; 
    return 0;  
}  