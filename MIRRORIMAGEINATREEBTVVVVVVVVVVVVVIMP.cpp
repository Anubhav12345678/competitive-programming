#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<map>
#include<vector>
#define ff first
#define se second
/*
You are given a binary tree rooted at 1. You have to find the mirror image of any node qi about node 1.
 If it doesn't exist then print -1.
Input:
First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node , second is child
 node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:
For each qi print it mirror node if it exists else print -1.
NOTE: 1 is mirror image of itself.
Constraints:
1 <= N <= 103
1<= Q <= 103


*/
struct TreeNode{
	  int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
ll mirror(TreeNode* left,TreeNode* right, int x){
	if(!left||!right) return 0;
	if(left->val==x) return right->val;
	if(right->val==x) return left->val;
	int mirrorval = mirror(left->left,right->right,x);
	if(mirrorval) return mirrorval;
	return mirror(left->right,right->left,x);
}

int main(){

   map<int,TreeNode*>  mp;
   int i,j,k,l,n,q,r,m,a,b,p;
   cin>>n>>q;
   mp[1] = new TreeNode(1);
   for(i=0;i<n-1;i++){
      int par,child;
	  char pos;
	  cin>>par>>child>>pos;
	  TreeNode* newnode = new TreeNode(child);
	  mp[child] = newnode;
	  if(pos=='L')
	  mp[par]->left = newnode;
	  else
	  mp[par]->right = newnode;
   }

   while(q--){
	   cin>>k;
	    if (mp[1]->val == k) {cout << k << endl; continue;}
	   int ans = mirror(mp[1]->left,mp[1]->right,k);
	   if(!ans) cout<<-1<<endl;
	   else
	   cout<<ans<<endl;
   }



	return 0;
}





