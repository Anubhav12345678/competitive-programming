#include <bits/stdc++.h>
using namespace std;
#include<string.h>
#include<vector>
bool comp(string x,string y)
{
    string xy = x.append(y);
    string yx = y.append(x);
    return (xy.compare(yx)>0)?1:0;
}
string largestNumber(const vector<int> &A) {
    int n = A.size();
    int i,j,k;
    vector<string> s(n);
    for(i=0;i<n;i++)
    s[i] = to_string(A[i]);
    string res = "";
    sort(s.begin(),s.end(),comp);
    // for(i=0;i<n;i++)
    // cout<<"s["<<i<<"] = "<<s[i]<<" ";
    for(i=0;i<n;i++)
    res+=s[i];
    return res;
    
}

int main() {
	int n,x,i;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	cout<<largestNumber(v)<<endl;
	// your code goes here
	return 0;
}