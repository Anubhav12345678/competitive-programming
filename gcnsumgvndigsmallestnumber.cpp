#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,s,l,r,sum;
	cin>>t;
	while(t--){
	    cin>>sum>>s;
	    int sm = sum;
	    l = pow(10,s-1),r = l*10-1;
	    if(9*s > sum){
	        while(l <= r){
	            int num = l;
	            while(num > 0){
	                sum -= num%10;
	                num /= 10;
	            }
	            if(sum == 0)
	                break;
	            else
	                sum = sm;
	            l++;
	        }
	        cout<<l<<endl;
	    }
	    else{
	        if(9*s == sum){
	            for(int i=0;i<s;i++)
	                cout<<"9";
	        }
	        else
	            cout<<"-1";
	        cout<<endl;
	    }
	}
	return 0;
}