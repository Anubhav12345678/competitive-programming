

/*

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two
 time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.



*/



class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        int n = tp.size();
        int i,j,k,l;
        vector<int> t(n);
        for(i=0;i<n;i++)
        {
            // cout<<tp[0]-'0'
            int hh = ((int)(tp[i][0]-'0')*10+(int)(tp[i][1]-'0'));
            int m = tp[i].size();
            int mm = (tp[i][m-2]-'0')*10+(tp[i][m-1]-'0');
            // cout<<"hh = "<<hh<<" mm = "<<mm<<endl;
            t[i] = hh*60+mm;
            // cout<<"t["<<i<<"] = "<<t[i]<<endl;
        }
        sort(t.begin(),t.end());
        int mindiff=INT_MAX;
       for(i=0;i<n;i++){
           for(j=i+1;j<n;j++)
           {
               mindiff= min(mindiff,min(t[j]-t[i],1440-t[j]+t[i]));
           }
       }
        
        return mindiff;
        
    }
};