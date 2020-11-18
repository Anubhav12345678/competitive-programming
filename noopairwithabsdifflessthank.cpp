#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i =0; i<n; i++){
			cin >> arr[i];
		}
		int k;
		cin >> k;
		sort(arr, arr+n, greater<int>());
		// for(int i =0; i<n; i++){
		// 	cout << arr[i] << " ";
		// }
		int sum = 0;
		for(int i=0; i<n; i++){
			if(i+1 <n && arr[i]-arr[i+1] < k){
				sum+= arr[i]+arr[i+1];
				i++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}