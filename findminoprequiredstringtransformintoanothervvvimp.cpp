#include<bits/stdc++.h>
using namespace std;
int minop(string s1,string s2)
{
	int i,j,k,l;
	int l1 = s1.size();
	int l2 = s2.size();
	int cnt=0;
	// we need to convert s1 into s2
	// only op allowed is to move  any char from s1 to front
	for(i=l1-1,j=i;i>=0;i--,j--)
	{
		while(i>=0&&s1[i]!=s2[j])
		{
			i--;
			cnt++;
		}
	}
	return cnt;
}
bool istransformable(string s1,string s2)
{
	if(s1.size()!=s2.size())
		return 0;
	unordered_multiset<char> chars1(s1.begin(),s1.end());
	unordered_multiset<char> chars2(s2.begin(),s2.end());
	return chars1==chars2;
}
// main function
int main()
{
	string first = "ADCB";
	string second = "ABCD";

	if (isTransformable(first, second))
	{
		cout << "Minimum operations required to convert the string "
			 << first << " to string " << second << " are "
			 << getMinimumOperations(first, second);
	}
	else {
		cout << "The string cannot be transformed";
	}

	return 0;
}





