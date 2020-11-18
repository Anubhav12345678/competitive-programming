#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
 clear cut idea : swap the element at even position in array A with the elements in the array B at even position then the problem becomes trivial given an array and find the sum of a given range 
*/
/*
Xsquare loves to play with arrays a lot. Today, he has two arrays named as A and B. Each array consists of N positive integers.

Xsquare has decided to fulfill following types of queries over his array A and array B.

1 L R : Print the value of AL + BL+1 + AL+2 + BL+3 + ... upto Rth term.
2 L R : Print the value of BL + AL+1 + BL+2 + AL+3 + ... upto Rth term.

*/
int main(){
	int N,Q;
	cin >> N >> Q;
	assert(N>=1 && N<=100000);
	assert(Q>=1 && Q<=100000);
	vector<ll> A(N+1),B(N+1);
	for(int i=1;i<=N;i++)
		cin >> A[i];
	for(int i=1;i<=N;i++)
		cin >> B[i];
	for(int i=2;i<=N;i+=2){
		swap(A[i],B[i]);	
	}	
	for(int i=1;i<=N;i++){
		A[i]+=A[i-1];
		B[i]+=B[i-1];
	}
	while(Q--){
		int c,l,r;
		cin >> c >> l >> r;
		assert(l<=r);
		if(c==1){
			if(l%2){
				cout << A[r]-A[l-1] << endl;
			}else{
				cout << B[r]-B[l-1] << endl;
			}
		}else{
			if(l%2 == 0){
				cout << A[r]-A[l-1] << endl;
			}else{
				cout << B[r]-B[l-1] << endl;
			}
		}			
	}
	return 0;
}