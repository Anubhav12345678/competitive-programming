#include<bits/stdc++.h>
using namespace std;
int n,t;
bool vis[30];
string s;
bool b;
vector<string> arr;

bool okay(vector<string>&arr1)
{
    
    for(int i=0;i<arr1.size()-1;i++)
    {
        int k=arr1[i].size()-1;
        if(arr1[i][k]!=arr1[i+1][0]) return false;
    }
    return true;
}
void solve(vector<string>& arr1)
{
    if(b)
    return;
    
    if(arr1.size()==arr.size())
    {
        int k=arr1[n-1].size()-1;
        if(arr1[n-1][k]==arr1[0][0])
           b=true;
        
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            arr1.push_back(arr[i]);
            if(okay(arr1))
            {
                solve(arr1);
            }
            arr1.pop_back();
            vis[i]=false;
            
        }
    }
}



int main()
{
cin>>t;

while(t--)
{
cin>>n;
vector<string>arr1;

for(int i=0;i<n;i++)
{
    cin>>s;
    arr.push_back(s);
}
memset(vis,false,sizeof(vis));

b=false;
solve(arr1);
cout<<b<<endl;
arr.clear();

}


}