#include<bits/stdc++.h>

using namespace std;
/*
There is a street in Lucknow which is famous for its street market.
 The street starts at point 0 and extends upto  units (you can think of these points on 
 a 1-D line starting at zero and extending to the right upto 10^9 ).

At a moment there are several customers and several street vendors on the street. Each customer in the street
 wants to reach a vendor as soon as possible. Can you tell for each customer how far is the nearest vendor and 
 in which direction, so that he/she can move to the correct position as desired.

Note: If a customer has nearest vendors at equal distance on both sides. Then the customer prefers to move left
*/
int main(){
   int n;
   cin>>n;
   vector<pair<int,int>> A(n);
   for(int i=0;i<n;i++){
       cin>>A[i].first;
       A[i].second = i;
   }
   int m;
   cin>>m;
   vector<int> B(m);
   for(auto &val:B) cin>>val;
   sort(A.begin(), A.end());
   sort(B.begin(), B.end());
   pair<int, char> ans[n];
   for (int i = 0; i < n;i++){
       int rti=lower_bound(B.begin(),B.end(),A[i].first)-B.begin();
       int rtd=INT_MAX;
       int lti = rti - 1;
       int ltd=INT_MAX;
       if (rti >= 0 && rti < m)
           rtd = min(rtd, abs(B[rti] - A[i].first));
       if (lti >= 0 && lti < m)
           ltd = min(ltd, abs(B[lti] - A[i].first));
           if(ltd<=rtd){
               ans[A[i].second] = {ltd, 'L'};
           }
           else{
               ans[A[i].second] = {rtd, 'R'};
           }
           if(ans[A[i].second].first==0) 
           ans[A[i].second].second='O';

   }
   for (int i = 0; i < n;i++){
       cout << ans[i].first << " " << ans[i].second << "\n";
   }

       return 0;
}