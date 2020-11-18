/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpiv(MountainArray &mountainArr,int l,int h)
    {
        cout<<"l = "<<l<<" h = "<<h<<endl;
        if(l>h)
            return -1;
        if(l==h)
            return mountainArr.get(l);
        int m = (l+h)/2;
        int x = mountainArr.get(m);
        int y = mountainArr.get(m-1);
        int z = mountainArr.get(m+1);
        if(m>l&&m<h&&x>y&&x>z)
            return m;
        if(m>l&&z<x)
            return findpiv(mountainArr,l,m);
        else
            return findpiv(mountainArr,m,h);
    }
    int binsearch(MountainArray &ma,int l,int h,int x)
    {
        if(l>h)
            return -1;
        int m = (l+h)/2;
        if(ma.get(m)==x)
            return m;
        if(ma.get(m)>x)
            return binsearch(ma,l,m-1,x);
        else
            return binsearch(ma,m+1,h,x);
    }
    int binsearch2(MountainArray &ma,int l,int h,int x)
    {
        if(l>h)
            return -1;
        int m = (l+h)/2;
        if(ma.get(m)==x)
            return m;
        if(ma.get(m)>x)
            return binsearch(ma,m+1,h,x);
        else
            return binsearch(ma,l,m-1,x);
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i,j,k,l;
        int n = mountainArr.length();
        cout<<"\n\n\n";
        int piv = findpiv(mountainArr,0,n-1);
        cout<<"\n\n\n";
        cout<<"piv = "<<piv<<endl;
        int x = binsearch2(mountainArr,piv+1,n-1,target);
        int y = binsearch(mountainArr,0,piv,target);
        cout<<x<<" "<<y<<endl;
        if(x==-1&&y==-1)
            return -1;
        // cout<<x<<" "<<y<<endl;
        if(x!=-1&&y!=-1)
            return min(x,y);
        else
            return max(x,y);
            
        
        
    }
};