class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        int i,j,k,l;
        vector<int> h(26,0);
        vector<int> smallest(26,101);
        for(i=0;i<n;i++)
        {
            for(j=0;j<A[i].size();j++)
            {
                h[A[i][j]-'a']++;
            }
            for(j=0;j<26;j++)
                if(smallest[j]>h[j])
                    smallest[j]=h[j];
            h = vector<int>(26,0);
        }
        // for(i=0;i<26;i++)
        // {
        //     cout<<i+'a'<<" "<<smallest[i]<<endl;
        // }
        vector<string> ans;
        ans.clear();
        for(i=0;i<26;i++)
        {
            while(smallest[i]>0)
            {
                string s(1,i+'a');
                ans.push_back(s);
                smallest[i]--;
            }
        }
        return ans;
        
        
    }
};