#include <iostream>
using namespace std;
#include<vector>
void generateMatrix(int A) {
    vector<vector<int>> res(A);
    int i=0,j=0,k=0,l=0,m=A,n=A;
    /* k - starting row index  
        m - ending row index  
        l - starting column index  
        n - ending column index  
        i - iterator  
    */
    int num=1;
    for(i=0;i<A;i++)
    res[i] = vector<int>(A,0);
    i=0;
    while(k<A&&l<A)
    {
        for(i=l;i<n;i++)
        {
        	// cout<<"num = "<<num<<endl;
        res[k][i] = num++;
        // cout<<"res["<<k<<"]["<<i<<"] = "<<res[k][i]<<endl;
        }
        k++;
        for(i=k;i<m;i++)
        {
        	// cout<<"num = "<<num<<endl;
        res[i][n-1] = num++;
        // cout<<"res["<<i<<"]["<<n-1<<"] = "<<res[k][i]<<endl;
        }
        n--;
        if(k<m)
        {
        for(i=n-1;i>=l;i--)
        {
        	// cout<<"num = "<<num<<endl;
        res[m-1][i] = num++;
        // cout<<"res["<<m-1<<"]["<<i<<"] = "<<res[k][i]<<endl;
        }
        m--;
        }
        if(l<n)
        {
        for(i=m-1;i>=k;i--)
        {
        	// cout<<"num = "<<num<<endl;
        res[i][l] = num++;
        // cout<<"res["<<i<<"]["<<l<<"] = "<<res[k][i]<<endl;
        }
        l++;
        }
    }
    for(i=0;i<A;i++)
    {
        for(j=0;j<A;j++)
        cout<<res[i][j]<<" ";
        cout<<endl;
    }
    
}

int main() {
	int n;
	cin>>n;
	generateMatrix(n);
	// your code goes here
	return 0;
}