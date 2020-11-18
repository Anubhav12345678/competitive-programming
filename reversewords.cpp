//meeeeeeeeeeeeee
class Solution {
public:
    string reverseWords(string s) {
        int i,j,k,l,n=s.size();
        if(n==0) return s;
        stack<char>  st;
        // string tmp="";
        i=0;
        while(i<n&&s[i]==' ') i++;
        if(i==n)
        {
            return "";
        }
        j=n-1;
        while(j>=0&&s[j]==' ') j--;
        for(k=i;k<=j;k++)
            st.push(s[k]);
        string res="",tmp = "";
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            if(c==' ')
            {
                if(tmp.size()==0) continue;
                reverse(tmp.begin(),tmp.end());
                res+=tmp+" ";
                tmp.clear();
                continue;
            }
            tmp.push_back(c); 
        }
        if(tmp.size()>0)
        {
            reverse(tmp.begin(),tmp.end());
                res+=tmp+" ";
                tmp.clear();

        }
        res.pop_back();
        return  res;
        
    }
};










#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
#include<vector>
#define pb push_back

void reverse(char *beg,char *end)
{
	char t;
	while(beg<end)
	{
		t = *beg;
		*beg++ = *end;// *(beg++) pointer aage badh jayega fir uski value me changes honge
		*end-- = t; //  *(end--)  poointer piche ho jayega fir uski value me changes honge
	}
}

void reverseword(char *s)
{
	char *word_beg = s;
	char *t = s;
	while(*t)
	{
		t++;
		if(*t=='\0')
		{
		 reverse(word_beg,t-1);	
		}
		else if(*t=='.')
		{
			reverse(word_beg,t-1);
			word_beg = t+1;
		}
	}
	
	reverse(s,t-1);
}
int main()
{
	ll sp[10001],t,i,j,l;
	char s[2001];
	cin>>t;
	getchar();
	while(t--)
	{
		
		cin>>s;
		reverseword(s);
		cout<<s<<endl;
//		ll dot=0;
//		getchar();
//		getline(cin,s);
//		l = s.size();
//		ll u=0,k=0;
//		for(i=0;i<l;i++)
//		if(s[i]=='.')
//		u++;
//	     for(i=l-1;i>=0;)
//	     {
//	     	j=i;
//	       while(s[i]!='.'&&i>=0)
//		   i--;
//		   for(k=i+1;k<=j;k++)
//		   cout<<s[k];
//		   if(dot<=u)
//		   {
//		   	cout<<'.';
//		   	dot++;
//		   }
//		   
//		   	
//		 }
       
		
		
	}
}