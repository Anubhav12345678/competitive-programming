#include <bits/stdc++.h>

using namespace std;

vector<int> v[100005];

// bool t=0;
/*

Shutterbug is on a treasure hunt today. He has reached the wall beyond which the treasure is kept. In order to break the wall he need to solve the puzzle engraved on it. The puzzle contains a tree with nodes N and and a key K (for sure an integer). For each node  in the tree  he needs to find "XOR of value of all the ancestors  of node  such that  number of direct children of ancestor  are greater than equal to K".

Value of a node is its index itself (1 based).

Note that root node is always 1 and for every node  he has to check the ancestors all upto 1.

Refer to sample explanation for further clarification.

Link for ancestor Ancestors



*/
int k;

bool visited[100005];

int child[100005],xor_till[100005];

void dfs(int root){

    if(visited[root])return;

    visited[root]=true;

    for(int i=0;i<(int)v[root].size();i++){

        if(!visited[v[root][i]]){

            child[root]++;

            dfs(v[root][i]);

        }

    }

}

void dfs1(int root){

    if(visited[root])return;

    visited[root]=true;

    for(int i=0;i<(int)v[root].size();i++){

        if(!visited[v[root][i]]){

            if(child[root]>=k){xor_till[v[root][i]]=xor_till[root]^root;}

            else xor_till[v[root][i]]=xor_till[root];

            // cout<<v[root][i]<<" "<<k<<" "<<xor_till[v[root][i]]<<endl;

            dfs1(v[root][i]);

        }

    }

}

int main(){

    int n;

    cin>>n>>k;

    for(int i=0;i<n-1;i++){

        int a,b;

        cin>>a>>b;

        v[a].push_back(b);

        v[b].push_back(a);

    }

    // for(int i=0;i<=n;i++)xor_till[i]=i;

    memset(visited,0,sizeof(visited));

    for(int i=1;i<=n;i++){

        if(!visited[i])

            dfs(i);

    }

    memset(visited,0,sizeof(visited));

        for(int i=1;i<=n;i++){

        if(!visited[i])

            xor_till[i]=0,dfs1(i);

    }

    for(int i=1;i<=n;i++){

            cout<<(xor_till[i])<<endl;

    }

}