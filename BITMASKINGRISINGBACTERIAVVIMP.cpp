int main ()
    {
        dance();
        int n,c=0;
        cin>>n;
        while(n)
        {
            n=n&(n-1);
            c++;
        }
        cout<<c<<endl;
        return 0;
 
    }