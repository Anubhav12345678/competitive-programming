class Solution {
public:
    bool chk(vector<int> &v,int a,int b,int m){
        if((b+m-1)>=v.size()) return false;
        for(int i=0;i<m;i++){
            if(v[i+a]!=v[i+b]) return 0;
        }
        return 1;
    }
    bool containsPattern(vector<int>& arr, int m, int k) {
        int i,j,l,n=arr.size();
        i=0;
        int  ans=1;
        for(i=0;i<n;i++){
            int nummatch=1;
            j=i+m;
            while(j+m-1<n){
                if(chk(arr,i,j,m))
                {
                    nummatch++;
                    j+=m;
                }
                else
                    break;
            }
            if(nummatch>=k) return true;
        }
        return  false;
    }
};
/*
Given an array of positive integers arr,  find a pattern of length m that is repeated k or more times.

A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively
 without overlapping. A pattern is defined by its length and the number of repetitions.

Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.
*/