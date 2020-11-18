#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
void showq(queue<int> gq)
{
  queue<int> g= gq;
  while(!g.empty())
  {
    cout<<g.front()<<" ";
    g.pop();
  }
  cout<<"\n";
}
int main()
{
  //vector stores th no in the same order n which they are inerted
//	std::vector<int> v;
////	ll i;
//	v.pb(5);
//	v.pb(6);
//	v.pb(8);
//	v.pb(7);
//	v.pb(13);
//	v.pb(45);
//	v.pb(67);
//	v.pb(90);
// sort(v.begin(), v.end()); //sort a vec in c++  
//	for(ll i=0;i<v.size();i++)
//	printf("%lld ",v[i]);
//	printf("\n");
//	for(ll i=v.size()-1;i>=0;i--)
//	printf("%lld ",v[i]);
//	printf("\n%lld \n",v[v.size()-1]);
//	v.insert(v.begin()+2,53);
//	for(ll i=0;i<v.size();i++)
//	printf("%lld ",v[i]);
//	printf("\n");
//	v.erase(v.begin()+2);
//	//	printf("%d %d %d",v.size(),v.begin(),v.end());
//	for(ll i=0;i<v.size();i++)
//	printf("%lld ",v[i]);
//	v.clear();
//	printf("\n%lld\n",v.size());

  /*
    lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
 
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
  // lower_bound and upper_bound in vector 
#include <iostream> 
#include <algorithm> // for lower_bound, upper_bound and sort 
#include <vector>  // for vector 

using namespace std; 

int main () 
{ 
  int gfg[] = {5,6,7,7,6,5,5,6}; 
  
  vector<int> v(gfg,gfg+8); // 5 6 7 7 6 5 5 6 

  sort (v.begin(), v.end()); // 5 5 5 6 6 6 7 7 

  vector<int>::iterator lower,upper; 
  lower = lower_bound (v.begin(), v.end(), 6); 
  upper = upper_bound (v.begin(), v.end(), 6); 

  cout << "lower_bound for 6 at position " << (lower- v.begin()) << '\n'; 
  cout << "upper_bound for 6 at position " << (upper - v.begin()) << '\n'; 

  return 0; 
} 
lower_bound for 6 at position 3
upper_bound for 6 at position 6
  */
//	for making use of make_pair in maps
  //myMap.insert(std::make_pair("first_key" , "first_value" ));
//	clear();
//    map<char[3], int> mp;
//    mp.insert(pair<char[3] , int>("abc",10));
//    mp.insert(pair<char[3] , int>("bbc",20));
//    mp.insert(pair<char[3] , int>("cbd",30));
//    mp.insert(pair<char[3] , int>("dfb",40));
//    mp.insert(pair<char[3] , int>("egb",50));
//    mp.insert(pair<char[3] , int>("fdf",60));
//    mp.insert(pair<char[3] , int>("gdb",70));
//    
//    map<char[], int>::iterator itr;
//    for(itr = mp.begin();itr!=mp.end();++itr)
//    {
//    	printf("\t%c\t%lld\n",itr->first,itr->second);
//	}
//    
//    printf("\n%lld %lld %lld\n",mp.begin(),mp.end(),mp.size());
//set begins
  // Sets are containers that store unique elements following a specific order.
  //Sets are typically implemented as binary search trees.
 set<int> s;
  s.insert(5);
  s.insert(75);
  s.insert(35);
  s.insert(45);
  s.insert(15);
  s.insert(4555);
  set<int>::iterator it;
  it = s.find(5);//Searches the container for an element equivalent to val and returns an iterator to it if found, otherwise it returns an iterator to set::end
  printf("%d\n",*it);
  s.erase(it);
  for(it = s.begin();it!=s.end();it++)
  printf("%d ",*it);
  s.insert(5);
  printf("\n");
  for(it = s.begin();it!=s.end();it++)
  printf("%d ",*it);
  //set ends
  
  // char s1[10001];
  // strcpy(s1,"anubhav");
  // printf("%s",s1);
  pq <int> g;
  //priority_queue::push() in C++ STL– push(g) function adds the element ‘g’ at the end of the queue.
  /*
      in c++ PRIORITY QUEUE IMPLEMENTS HEAP
   */
  pq.push();
  //heap on size on can be created in O(k) time
  queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(20); 
    gquiz.push(30); 
  
    cout << "The queue gquiz is : "; 
    showq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.front() : " << gquiz.front(); //returns a ref to front ele of queue
    cout << "\ngquiz.back() : " << gquiz.back(); //returns a ref to front ele of queue
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); //deletes the front ele of the queue
    showq(gquiz); 
  
    return 0;
   //

   /*frequency cal with the help of map 

   #include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#include<limits.h>
#define V 9
#define inf INT_MAX
#define mp make_pair
int main() {
  ll t,i,j,a[1001],n;
  map<ll,ll> mymap;
  map<ll,ll>::iterator it;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
      mymap[a[i]]++;
  }
  for(it = mymap.begin();it!=mymap.end();++it)
  {
    cout<<it->first<<" "<<it->second<<"\n";
  }
  // your code goes here
  return 0;
}

    */
	
	
	/*priority queue
  #include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#include<limits.h>
#define V 9
#define inf INT_MAX
#define mp make_pair
#define ff first
#define ss second
int main() {
  pq<pair<ll ,ll>,vector<pair<ll, ll>>,greater<pair<ll, ll>>> m;
    ll x,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
    cin>>x;
    m.push(mp(i,x));
    }
    // pq<pair<ll,ll>>::iterator it;
    while(!m.empty())
    {
       pair<ll ,ll> myp =  m.top();
       cout<<myp.first<<" "<<myp.ss<<endl;
       m.pop();
    }
    
    
  // your code goes here
  return 0;
}

  */


/*  implementation ofmax heap using priority queue  */
//  see https://ideone.com/E5hfUh for full code & res
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#define pi pair<ll, ll>
#define f first
#define s second
#define mp make_pair
// ..implementation ofmax haep using priority queue
 
int main() {
  pq<pair<ll, ll>> q;
  q.push(mp(20, 100));
  q.push(mp(10, 120));
  q.push(mp(15,130));
  pair<ll ,ll> top = q.top();
  cout<<top.f<<" "<<top.s<<endl;
 
  // your code goes here
  return 0;
}  

// implementation of min heap using priority queue
// see https://ideone.com/3InTx1 for full code & res
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#define pi pair<ll, ll>
#define f first
#define s second
#define mp make_pair
// ..implementation of min heap using priority queue
 
int main() {
  pq<pair<ll, ll>,vector<pair<ll, ll>>,greater<pair<ll ,ll>>> q;
  q.push(mp(20, 100));
  q.push(mp(10, 120));
  q.push(mp(15,130));
  pair<ll ,ll> top = q.top();
  cout<<top.f<<" "<<top.s<<endl;
 
  // your code goes here
  return 0;
}


}

  #include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#define pi pair<ll, ll>
#define f first
#define s second
#define mp make_pair
// ..implementation ofmax haep using priority queue
 
int main() {
  pq<pair<ll, ll>,vector<pair<ll, ll>>,greater<pair<ll ,ll>>> q;
  q.push(mp(20, 100));
  q.push(mp(10, 120));
  q.push(mp(15,130));
  auto it = q.top();
  while(!q.empty())
  {
    it = q.top();
    cout<<it.first<<" "<<it.second<<endl;
    q.pop();
  }
 
  // your code goes here
  return 0;
}
//output 
// 10 120
// 15 130
// 20 100
// for full detail view https://ideone.com/ybK9xk
//

//                                STACK
The functions associated with stack are:
empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)

filter_none
edit
play_arrow

brightness_4
// CPP program to demonstrate working of STL stack 
#include <iostream> 
#include <stack> 
using namespace std; 
  
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
} 
// min heap using proiority queue
// CPP code to count the change required to 
// convert the array into non-increasing array 
#include <bits/stdc++.h> 
using namespace std; 

void show(int a[],int n)
{
  int i,j,k;
  priority_queue<int, vector<int>, greater<int> > pq; 
  for(i=0;i<n;i++)
  pq.push(a[i]);
  for(i=0;i<n;i++)
  {
    cout<<pq.top()<<endl;
    pq.pop();
  }
}

// Driver Code 
int main() 
{ 
  int a[] = { 3, 1, 2, 1 }; 
  int n = sizeof(a) / sizeof(a[0]); 

  show(a, n); 

  return 0; 
} 
//The functions for deque are same as vector, with an addition of push and pop operations for both front and back.
#include <iostream> 
#include <deque> 

using namespace std; 

void showdq(deque <int> g) 
{ 
  deque <int> :: iterator it; 
  for (it = g.begin(); it != g.end(); ++it) 
    cout << '\t' << *it; 
  cout << '\n'; 
} 

int main() 
{ 
  deque <int> gquiz; 
  gquiz.push_back(10); 
  gquiz.push_front(20); 
  gquiz.push_back(30); 
  gquiz.push_front(15); 
  cout << "The deque gquiz is : "; 
  showdq(gquiz); 

  cout << "\ngquiz.size() : " << gquiz.size(); 
  cout << "\ngquiz.max_size() : " << gquiz.max_size(); 

  cout << "\ngquiz.at(2) : " << gquiz.at(2); 
  cout << "\ngquiz.front() : " << gquiz.front(); 
  cout << "\ngquiz.back() : " << gquiz.back(); 

  cout << "\ngquiz.pop_front() : "; 
  gquiz.pop_front(); 
  showdq(gquiz); 

  cout << "\ngquiz.pop_back() : "; 
  gquiz.pop_back(); 
  showdq(gquiz); 

  return 0; 
} 
