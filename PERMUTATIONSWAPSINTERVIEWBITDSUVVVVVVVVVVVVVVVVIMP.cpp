/*
Rishabh has a permutation A of N integers 1, 2, ... N but he doesn't
 like it. Rishabh wants to get a permutation B.

Also, Rishabh has some M good pairs given in a form of 2D matrix C of
 size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.

In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing
 the above operation any number of times on permutation A.

If the permutation B can be obtained return 1 else return 0.



Problem Constraints
2 <= N <= 105
1 <= M <= 105


*/



vector<int> par;
int find(int i){
    if(par[i]==i) return i;
    return par[i]=find(par[i]);
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
     int n  =A.size();
     int i,j,k,l,m;
     par.resize(n+1);
     for(int i=1;i<=n;i++)
     par[i]=i;
     for(auto e:C){
         int x = A[e[0]-1];
         int y= A[e[1]-1];
         int px = find(x);
         int py =  find(y);
         if(px!=py)
         par[py]=px;
     }
     
     for(int i=0;i<n;i++){
         if(A[i]!=B[i]){
             int a = find(A[i]);
             int b = find(B[i]);
             if(a!=b) return 0;
         }
     }
     return 1;
    
}
