// LEETCODE
class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int x){
        if(par[x]==-1) return x;
        return par[x]=find(par[x]);
    }
    void merge(int x,int y){
        int a = find(x);
        int b = find(y);
        if(a==b) return;
        if(rank[a]>=rank[b]){
            rank[a]+=rank[b];
            par[b]=x;
        }
        else{
            rank[b]+=rank[a];
            par[a]=b;
        }
    }
    int largestComponentSize(vector<int>& a) {
           int i,j,k,l,n=a.size();
        par=vector<int>(n,-1);
        rank = vector<int>(n,1);
        int res=1;
        map<int,int> m;
        for(i=0;i<n;i++){
            int x = a[i];
            for(j=2;j*j<=x;j++){
                if(x%j==0){
                    if(m.count(j))
                        merge(m[j],i);
                    else
                        m[j]=i;
                    if(m.count(x/j))
                        merge(m[x/j],i);
                    else
                        m[x/j]=i;
                }
            }
            if(m.count(x))
                merge(m[x],i);
            else
                m[x]=i;
            res=  max(res,rank[find(i)]);
        }
        return res;
    }
};

// gfg
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<set>
int spf[100005];//  smallest prime factor
int id[100005];
int par[100005];
int szcontainer[100005];
/*
Given a graph with N nodes and their values defined in array A, the task is
 to find the largest component size in a graph by connecting non-co-prime nodes. 
 An edge is between two nodes U and V if they are non-co-prime which means that the
  greatest common divisor of A[U] and A[V] should be greater than 1.

Examples:

Input : A = [4, 6, 15, 35]
Output : 4
Graph will be :
         4
         |
         6
         |
         15
         |
         35

Input : A = [2, 3, 6, 7, 4, 12, 21, 39]
Output : 8

*/
void sieve(){
	int i,j,k,l,n,m;
	memset(spf,0,sizeof(spf));
	
	spf[0] = spf[1]=0;
	for(i=2;i<100005;i++){
		if(spf[i]==0)
		spf[i]=i;
		for(j=2*i;j<100005;j+=i)
		{
			if(spf[j]==0)
			spf[j]=i;
		}
	}
}

void factorise(int x,set<int> &s){
	while(x>1){
		int z= spf[x];
		s.insert(z);
		while(x%z==0)
		x/=z;
	}
}
int find(int x){
	if(par[x]==x) return par[x];
	return par[x] = find(par[x]);
}

void merge(int a,int b){
	int x = find(a);
	int y = find(b);
	if(x==y) return;
	if(szcontainer[x]>szcontainer[y])
	swap(x,y);
	par[x]=y;
	szcontainer[y]+=szcontainer[x];
}

int maxcontainersz(int a[],int n){
	int i,j,k,l,m,ans=0;
	memset(id,0,sizeof(id));
	for(i=0;i<100005;i++){
		par[i]=i;
		szcontainer[i]=1;
	}
	sieve();
	for(i=0;i<n;i++){
		set<int> st;
		factorise(a[i],st);
		for(auto it:st){
			if(id[it]==0)
			id[it] = i+1;
			else
			merge(i+1,id[it]);
		}
	}
	for(i=0;i<n;i++)
	ans = max(ans,szcontainer[i]);
	return ans;
	
}
int main() {
	
	int n = 8; 
    int A[] = { 2, 3, 6, 7, 4, 12, 21, 39 }; 
   
    cout << maxcontainersz(A, n); 
   
    return 0; 
	// your code goes here
	return 0;
}