
/*
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the
 third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.


*/



vector<int> Solution::maxset(vector<int> &A) {
    vector<int>result;
    int n=A.size();
    // long long int i,start=0,ending=0,a=0,b=0,sum=A[0],max=-1,j;
     int st=0,en=-1,i=0,j,k,l;
     long long int sum=0,maxsum=0,fst=-1,fen=-1,cnt=0,maxm=0;
     while(i<n)
     {
         if(A[i]>=0)
         {
             cnt++;
             sum+=A[i];
             en++;
         }
         if(sum>maxsum)
         {
             maxsum=sum;
             fst=st;
             fen = en;
         }
         else if(sum==maxsum&&cnt>maxm)
         {
             fst=st;
             fen=en;
             maxm=cnt;
         }
         if(A[i]<0)
         {
             cnt=0;
             sum=0;
             st=i+1;
             en=i;
         }
         i++;
     }
     if(sum>maxsum)
         {
             maxsum=sum;
             fst=st;
             fen = en;
         }
         vector<int> res;
         res.clear();
        if(fst!=-1&&fen!=-1)
        for(i=fst;i<=fen;i++)
        {
            res.push_back(A[i]);
        }
        return res;
     
}
