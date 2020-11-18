#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	//code 
	int t; 
	cin>>t; 
	cin.ignore(); 
	
	while(t--) 
	{ 
		string s; 
		getline(cin, s); 
		
		string x, y; 
		getline(cin, x); 
		getline(cin, y); 
		
		reverse(s.begin(), s.end()); 
		reverse(x.begin(), x.end()); 
		reverse(y.begin(), y.end()); 

		int ls = s.length(), lx = x.length(), ly = y.length(); 
		int d = ly - lx; 
		int ct = 0; 
		int i = 0, j=0; 
		
		while(i<ls) 
		{ 
			string temp = ""; 
			for(int k=0;k<lx;k++) 
			{ 
				temp += s[i+k]; 
			} 
			
			if(temp == x) 
			{ 
				ct++; 
				i = i+lx; 
			} 
			else
			{ 
				i = i+1; 
			} 
		} 
		
		for(int i=0;i<ct*d;i++) 
		s += ' '; 
		
		i = ls-1; j = ls+ct*d - 1; 

		while(i>=0 && j>=0) 
		{ 
			string temp = ""; 
			for(int k=0;k<lx;k++) 
			{ 
				if(i<(lx-1-k)) 
				break; 
				
				temp += s[i-(lx-1-k)]; 
			} 
			
			if(temp == x) 
			{ 
				int k=ly-1; 
				while(k>=0) 
				s[j--] = y[k--]; 
				
				i = i - lx; 
			} 
			else
			{ 
				s[j--] = s[i--]; 
			} 
		} 
		reverse(s.begin(), s.end()); 
		cout<<s<<endl; 
	} 
	return 0; 
} 
