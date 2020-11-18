#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, x, y;
  cin>>t;
  int count[100001];
  int ans;
  while(t>0){
    t--;
    memset(count, 0, 100001*sizeof(count[0]));
    ans = 0;
    cin>>n;
    for(int i=1; i<n; i++){
      cin>>x>>y;
      count[x-1]++;
      count[y-1]++;
    }
    for(int i=0; i<n; i++){
      cin>>x;
      if(x!=0 && count[i]>1 ){
        ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
/*
Given a tree with  nodes with some non-negative value assigned to it. Lets say that the value of the  node is . The beauty of 
a path between nodes  and  (denoted by ) is described as the sum of values of all nodes that lie on the path excluding the nodes 
 and . Note that  is always zero for any valid node . Ash is a weird guy. He only likes trees that have . In one operation Ash can
  change the value of any node to any non-negative value. Ash wants to find the minimum number of operations required so that he
   starts liking the given tree. But Ash does not have time to solve the problem as he is on his Pokemon adventure. So he needs 
   your help in solving this problem.

*/