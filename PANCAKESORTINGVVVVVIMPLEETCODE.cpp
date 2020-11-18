
/*

Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the
 first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the 
 array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 
10 * A.length flips will be judged as correct.

 

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.



*/




class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int i,j,k,l,n=A.size();
        vector<int> res;
        for(i=n;i>0;i--)
        {
            int x=0;
            for(j=0;j<i;j++) if(A[j]>A[x]) x=j;
            res.push_back(x+1);
            reverse(A.begin(),A.begin()+x+1);
            cout<<"x = "<<x<<endl;
            for(k=0;k<n;k++) cout<<"A["<<k<<"]="<<A[k]<<" ";
            res.push_back(i);
            reverse(A.begin(),A.begin()+i);
            cout<<"\nbadme\n";
            for(k=0;k<n;k++) cout<<"A["<<k<<"]="<<A[k]<<" ";
        }
        return res;
    }
};