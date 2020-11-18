vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
   int n = A.size();
   int N = 2*n-1,i,j;
   vector<vector<int>> res(N);
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   res[i+j].push_back(A[i][j]);
   return res;
}
/*
     Input: 	

     1 2 3
     4 5 6
     7 8 9

     Return the following :

     [ 
       [1],
       [2, 4],
       [3, 5, 7],
       [6, 8],
       [9]
     ]





*/