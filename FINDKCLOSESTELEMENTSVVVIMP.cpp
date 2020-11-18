class Solution {
public:
    int findpiv(vector<int> &v,int x,int low,int high)
    {
        if(v[high]<x)
            return high;
        if(v[low]>x)
            return low;
        int m = low+(high-low)/2;
        if(m<high&&v[m]<=x&&v[m+1]>x)
            return m;
        else if(v[m]<x)
            return findpiv(v,x,m+1,high);
        return findpiv(v,x,low,m-1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        res.clear();
        int n = arr.size();
        if(n<=1)
            return arr;
        int i,j,l;
        l = findpiv(arr,x,0,n-1);
       int r=l+1;
        int cnt=0;
        cout<<"l = "<<l<<endl;
        if(arr[l]==x) res.push_back(x),l--,cnt++;//r=l+1;
        while(l>=0&&r<n&&cnt<k)
        {
            if(x-arr[l]<=arr[r]-x)
                res.push_back(arr[l--]);
            else
                res.push_back(arr[r++]);
            cnt++;
        }
         while(cnt<k&&l>=0)
        {
            res.push_back(arr[l--]);
            cnt++;
        }
        while(cnt<k&&r<n)
        {
            res.push_back(arr[r++]);
            cnt++;
        }
        // while(cnt<k&&l>=0)
        // {
        //     res.push_back(arr[l--]);
        //     cnt++;
        // }
        sort(res.begin(),res.end());
        return res;
    }
};