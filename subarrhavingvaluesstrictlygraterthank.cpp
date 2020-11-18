#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    int arr[n];
	    for(int i=0;i<n;i++)    cin >> arr[i];
	    int cnt=0;
	    int sum=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]<=k){
	            cnt++;
	        }
	        else{
	            sum+=(cnt*(cnt+1)/2);
	            cnt=0;
	        }
	    }
	    sum+=(cnt*(cnt+1)/2);
	    int total=(n*(n+1)/2);
	    cout << total-sum << endl;
	}
	return 0;
}