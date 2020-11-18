#include <iostream>
using namespace std;
#include<stack>
int precedence(char c)
{
	if(c=='+'||c=='-') return 1;
	if(c=='*'||c=='/') return 2;
	return 0;
}
int applyop(int a,int b,char op)
{
	if(op=='+') return a+b;
	if(op=='-') return a-b;
	if(op=='*') return a*b;
	if(op=='/') return a/b;
	return 0;
}
int solve(string s)
{
	int i,j,k,l;
	stack<int> vals;
	stack<char> st;
	int n = s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]==' ') continue;
		else if(s[i]=='(') st.push(s[i]);
		else if(s[i]>='0'&&s[i]<='9')
		{
			int v=0;
			while(i<n&&(s[i]>='0'&&s[i]<='9'))
			{
				v = v*10+(s[i]-'0');
				i++;
			}
			vals.push(v);
		}
		else if(s[i]==')')
		{
			while(!st.empty()&&st.top()!='(')
			{
				int x = vals.top();
				vals.pop();
				int y = vals.top();
				vals.pop();
				char op = st.top();
				st.pop();
				vals.push(applyop(x,y,op));
			}
			if(!st.empty())
			st.pop();
		}
		else
		{
			while(!st.empty()&&precedence(st.top())>=precedence(s[i]))
			{
				int x = vals.top();
				vals.pop();
				int y = vals.top();
				vals.pop();
				char op = st.top();
				st.pop();
				vals.push(applyop(x,y,op));
			}
			st.push(s[i]);
		}
	}
	
	while(!st.empty())
	{
		        int x = vals.top();
				vals.pop();
				int y = vals.top();
				vals.pop();
				char op = st.top();
				st.pop();
				vals.push(applyop(x,y,op));
	}
	return vals.top();
}
int main() {
	cout << solve("10 + 2 * 6") << "\n"; 
    cout << solve("100 * 2 + 12") << "\n"; 
    cout << solve("100 * ( 2 + 12 )") << "\n"; 
    // cout << evaluate("100 * ( 2 + 12 ) / 14"); 
    return 0; 
	// your code goes here
	return 0;
}