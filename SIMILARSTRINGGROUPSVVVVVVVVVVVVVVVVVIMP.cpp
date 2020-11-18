
    /*
Two strings X and Y are similar if we can swap two letters (in different positions)
 of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats"
 and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and
 {"star"}.  Notice that "tars" and "arts" are in the same group even though they are
  not similar.  Formally, each group is such that a word is in the group if and only 
  if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

 

Example 1:

Input: A = ["tars","rats","arts","star"]
Output: 2



    */
   class Solution {
public:
    vector<int> par;
    int find(int i){
        if(par[i]==i) return i;
        return par[i] = find(par[i]);
    }
    bool comp(string &a,string &b){
        int i,j,k,l,cnt=0;
        for(i=0;i<a.size();i++)
            if(a[i]!=b[i]) cnt++;
        return cnt<=2;
    }
    int numSimilarGroups(vector<string>& A) {
       int i,j,k,l,n=A.size();    
       par.resize(n+1);
        for(i=0;i<par.size();i++)
            par[i] = i;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(comp(A[i],A[j])){
                    int x = find(i);
                    int y = find(j);
                    if(x!=y)
                        par[y]=x;
                }
            }
        }
        int cnt=0;
        for(i=0;i<n;i++)
            if(par[i]==i)
                cnt++;
        return cnt;
    }
};