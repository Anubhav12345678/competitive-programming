#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int>a;
//you don't have to use set, it was just easier for us

int main(){
  int T; cin>>T;
  while (T--){
    int N,X;
    cin>>N>>X;
    int far=0; //largest favorite number
    for (int i=0;i<N;i++){
      int A;
      cin>>A;
      a.insert(A);
      far=max(far,A);
    }
    if (a.count(X)) //X is favorite number
      cout<<1<<endl;
    else
      cout<<max(2,(X+far-1)/far)<<endl; //expression as explained in tutorial
    a.clear();
  }
}
/*

Bessie has way too many friends because she is everyone's favorite cow! Her new friend Rabbit is 
trying to hop over so they can play!

More specifically, he wants to get from (0,0) to (x,0) by making multiple hops. He is only willing to hop 
from one point to another point on the 2D plane if the Euclidean distance between the endpoints of a hop is one
 of its n favorite numbers: a1,a2,…,an. What is the minimum number of hops Rabbit needs to get from (0,0) to (x,0)?
  Rabbit may land on points with non-integer coordinates. It can be proved that Rabbit can always reach his destination.

Recall that the Euclidean distance between points (xi,yi) and (xj,yj) is (xi−xj)2+(yi−yj)2−−−−−−−−−−−−−−−−−−√.

For example, if Rabbit has favorite numbers 1 and 3 he could hop from (0,0) to (4,0) in two hops as shown below. Note
 that there also exists other valid ways to hop to (4,0) in 2 hops (e.g. (0,0) → (2,−5–√) → (4,0)).

Here is a graphic for the first example. Both hops have distance 3, one of Rabbit's favorite numbers.
In other words, each time Rabbit chooses some number ai and hops with distance equal to ai in any direction he wants.
 The same number can be used multiple times.



*/