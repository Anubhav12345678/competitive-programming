#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &A) {
	// cout<<"entered function\n";
    int n = A.size();
    // cout<<"n= "<<n<<endl;
    reverse(A.begin(),A.end());
    // for(int p = 0;p<n;p++)
    // cout<<A[p]<<" ";
    // cout<<endl;
    A.push_back(0);
    n = A.size();
    // for(int p = 0;p<n;p++)
    // cout<<A[p]<<" ";
    // cout<<endl;
    int i,j,k,car=0;
    A[0]+=1;
    car = A[0]/10;
    A[0] = A[0]%10;
    // cout<<"A[0] = "<<A[0]<<endl;
    // cout<<"car = "<<car<<endl;
    if(car)
    {
    	// cout<<"entere if\n";
        for(i=1;i<n;i++)
        {
            if(car)
            {
                A[i]+=car;
                car = A[i]/10;
                A[i] = A[i]%10;
            }
        }
    }
    while(!A.empty()&&A[A.size()-1]==0)
    A.pop_back();
    reverse(A.begin(),A.end());
    // for(int p = 0;p<n;p++)
    // cout<<A[p]<<" ";
    // cout<<endl;
    // if(A[0]==0)
    // {
    //     i=0;
    //     while(A[i]==0)
    //     {
            
    //         i++;
    //     }
    // }
     return A;
    
    
}
int main()
{
	vector<int> A;
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>j;
		A.push_back(j);
	}
	A = plusOne(A);
	for(i=0;i<n;i++)
	cout<<A[i]<<" ";
	
}
