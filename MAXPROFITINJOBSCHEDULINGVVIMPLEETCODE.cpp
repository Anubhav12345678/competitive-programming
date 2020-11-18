class Solution {
public:
    // // static bool comp(vector<int> a,vector<int> b)
    // // {
    // //     if(a[1]==b[1])
    // //         return a[0]<b[0];
    // //     else
    // //         return a[1]<b[1];
    // // }
    // int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    //     vector<vector<int>> jobs({vector<int>({-1,0,0})});
    //     int n=startTime.size();
    //     for(int i=0;i<n;i++)jobs.push_back(vector<int>({startTime[i],endTime[i],profit[i]}));
    //     sort(jobs.begin(),jobs.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1]||(a[1]==b[1])&&(a[0]<b[0]);});
    //     int f[50010];memset(f,0,sizeof(f));
    //     for(int i=1;i<=n;i++)
    //     {
    //         int k=jobs[i][0];
    //         int low=0,high=i-1,mid=(low+high)/2;
    //         while(low<high)
    //         {
    //             if(jobs[mid+1][1]<=jobs[i][0])low=mid+1;
    //             else high=mid;
    //             mid=(low+high)/2;
    //         }
    //         f[i]=max(f[i-1],f[mid]+jobs[i][2]);
    //     }
    //     return f[n];
    //     // int n = profit.size();
    //     // vector<vector<int>> jobs;
    //     // int i,j,k,l,h;
    //     // for(i=0;i<n;i++)
    //     // {
    //     //     jobs.push_back({startTime[i],endTime[i],profit[i]});
    //     // }
    //     // sort(jobs.begin(),jobs.end(),comp);
    //     // int f[50001];
    //     // memset(f,0,sizeof(f));
    //     // for(i=1;i<=n;i++)
    //     // {
    //     //     l=0,h=i-1;
    //     //     int mid = (l+h)/2;
    //     //     while(l<h)
    //     //     {
    //     //         if(jobs[mid+1][1]<=jobs[i][0]) l=mid+1;
    //     //         else h=mid;
    //     //         mid = (l+h)/2;
    //     //     }
    //     //     f[i]= max(f[i-1],f[mid]+jobs[i][2]);
    //     // }
    //     // return f[n];
    class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        else
            return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // vector<vector<int>> jobs({vector<int>({-1,0,0})});
        // int n=startTime.size();
        // for(int i=0;i<n;i++)jobs.push_back(vector<int>({startTime[i],endTime[i],profit[i]}));
        // sort(jobs.begin(),jobs.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1]||(a[1]==b[1])&&(a[0]<b[0]);});
        // int f[50010];memset(f,0,sizeof(f));
        // for(int i=1;i<=n;i++)
        // {
        //     int k=jobs[i][0];
        //     int low=0,high=i-1,mid=(low+high)/2;
        //     while(low<high)
        //     {
        //         if(jobs[mid+1][1]<=jobs[i][0])low=mid+1;
        //         else high=mid;
        //         mid=(low+high)/2;
        //     }
        //     f[i]=max(f[i-1],f[mid]+jobs[i][2]);
        // }
        // return f[n];
        int n = profit.size();
        vector<vector<int>> jobs({vector<int>({-1,0,0})});
        int i,j,k,l,h;
        for(i=0;i<n;i++)
        {
            jobs.push_back(vector<int>({startTime[i],endTime[i],profit[i]}));
        }
        sort(jobs.begin(),jobs.end(),comp);
        int f[50010];
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            l=0,h=i-1;
            int mid = (l+h)/2;
            while(l<h)
            {
                if(jobs[mid+1][1]<=jobs[i][0]) l=mid+1;
                else h=mid;
                mid = (l+h)/2;
            }
            f[i]= max(f[i-1],f[mid]+jobs[i][2]);
        }
        return f[n];
    }
};

    }
};