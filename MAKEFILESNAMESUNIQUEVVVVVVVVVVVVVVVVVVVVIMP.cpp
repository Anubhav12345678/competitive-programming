class Solution {
public:
    /*
Given an array of strings names of size n. You will create n folders in your file system such that, at the ith minute, you will create a folder with the name names[i].

Since two files cannot have the same name, if you enter a folder name which is previously used, the system will have a suffix addition to its name in the form of (k), where, k is the smallest positive integer such that the obtained name remains unique.

Return an array of strings of length n where ans[i] is the actual name the system will assign to the ith folder when you create it.

 

Example 1:

Input: names = ["pes","fifa","gta","pes(2019)"]
Output: ["pes","fifa","gta","pes(2019)"]
Explanation: Let's see how the file system creates folder names:
"pes" --> not assigned before, remains "pes"
"fifa" --> not assigned before, remains "fifa"
"gta" --> not assigned before, remains "gta"
"pes(2019)" --> not assigned before, remains "pes(2019)"



    */
    vector<string> getFolderNames(vector<string>& names) {
        
        unordered_map<string,int> mp;
        int i,j,k,l,n=names.size();
        vector<string> res;
        for(i=0;i<n;i++)
        {
            int x = mp[names[i]];
            if(x==0)
            {
                mp[names[i]]=1;
                res.push_back(names[i]);
            }
            else
            {
                while(mp.count(names[i]+"("+to_string(x)+")")) x++;
                res.push_back(names[i]+"("+to_string(x)+")");
                mp[names[i]+"("+to_string(x)+")"] = 1;
                mp[names[i]]=x;
            }
        }
        return res;
    }
};