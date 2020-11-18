#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a;
        if(n>=0)
            a.push_back(0);
        
        queue <int> qu;
        
        for(int i=1;i<10;i++)
        {
        	cout<<"i = "<<i<<endl;
            qu.push(i);
            cout<<"qu.front() = "<<qu.front()<<endl;
            while(!qu.empty())
            {
                int temp=qu.front();
                cout<<"temp = "<<temp<<endl;
                qu.pop();
                cout<<"qu.front() = "<<qu.front()<<endl;
                if(temp > n)
                {
                	cout<<"continue\n";
                	continue;
                }
                
                  //continue;
               
                a.push_back(temp);
                int l=temp%10;
                cout<<"l = "<<l<<endl;
                if(l>0)
                {
                	cout<<"temp = "<<temp<<" temp*10+(l-1) = "<<temp*10+(l-1)<<endl;
                 qu.push(temp*10+(l-1));
                }
                if(l<9)
                {
                 cout<<"temp = "<<temp<<" temp*10+(l-1) = "<<temp*10+(l+1)<<endl;	
                 qu.push(temp*10+(l+1));
                }
            }
        }
        sort(a.begin(),a.end());
        for(auto it=a.begin();it!=a.end();it++)
           cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}