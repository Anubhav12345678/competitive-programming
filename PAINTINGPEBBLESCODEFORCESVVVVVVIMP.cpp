#include<bits/stdc++.h>
using namespace std;
int mx=0,mi=101,a[101],n,k,j;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	if(mx-mi>k){
		cout<<"NO"<<endl;return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;++i){
		for(j=0;j<a[i]-1;++j){
			cout<<(j%k)+1<<" ";
		}
		cout<<(j%k)+1<<endl;
	}
}
/*
There are n piles of pebbles on the table, the i-th pile contains a i pebbles. Your task is to paint each pebble using one of the k given colors so that for each color c and any two piles i and j the difference between the number of pebbles of color c in pile i and number of pebbles of color c in pile j is at most one.

In other words, let's say that b i, c is the number of pebbles of color c in the i-th pile. Then for any 1 ≤ c ≤ k, 1 ≤ i, j ≤ n the following condition must be satisfied |b i, c - b j, c| ≤ 1. It isn't necessary to use all k colors: if color c hasn't been used in pile i, then b i, c is considered to be zero.


*/