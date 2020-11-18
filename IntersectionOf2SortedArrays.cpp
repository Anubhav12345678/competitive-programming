vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
 vector<int>res;
  res.clear();
  int n = A.size();
  int m = B.size();
  //cout<<"n= "<<n<<" m = "<<m<<endl;
  int i=0,j=0,k=0,p,q;
  vector<int> s;
  s.clear();
//   map<int,int> m1,m2;
// //   for(i=0;i<n;i++)
// //   m1[A[i]]++;
// //   for(j=0;j<m;j++)
// //   m2[B[j]]++;
  i=0;
  j=0;
  //cout<<A[0]<<endl;
  while(i<n&&j<m)
  {
      // cout<<"in while\n";
      // cout<<"A["<<i<<"]= "<<A[i]<<" B["<<j<<"] = "<<B[j]<<endl;
      if(A[i]<B[j])
      i++;
      else if(A[i]>B[j])
      j++;
      else
      {
          s.push_back(A[i]);
        //   s.push_back(B[j]);
          k++;
          i++;
          j++;
      }
  }
//   if(s.size()==0)
//   return res;
//   //cout<<s.size()<<endl;
//   for(auto it = s.begin();it!=s.end();++it)
//   {
//         //cout<<*it<<endl;
//       int x = min(m1[*it],m2[*it]);
//       for(i=0;i<x;i++)
//       res.push_back(*it);
//   }
 // cout<<"insidefun\n";
 // for(int i=0;i<res.size();i++)
    // cout<<res[i]<<" ";
  return s;
  
}

//LEETCODE
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i,j,k,l;
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        i=j=0;
        while(i<n&&j<m)
        {
            if(nums1[i]>nums2[j])
                j++;
            else if(nums1[i]<nums2[j])
                i++;
            else
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
