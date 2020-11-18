// C++ program for implementation of KMP pattern searching 
// algorithm 
// https://ideone.com/j2yhT7
#include <bits/stdc++.h> 
using namespace std;
void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
  int M = strlen(pat);
  int N = strlen(txt);
  int lps[M];
  computeLPSArray(pat,M,lps);
  int i=0,j=0,k,l;
  while(i<N)
  {
  	if(txt[i]==pat[j])
  	{
  		i++;
  		j++;
  	}
  	if(j==M)
  	{
  		cout<<"Pat found at ind "<<i-j<<endl;
  		j=lps[j-1];
  	}
  	else if(i<N&&txt[i]!=pat[j])
  	{
  		if(j!=0)
  		j = lps[j-1];
  		else
  		i++;
  	}
  }
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
   int len=0,i=0,j,k,l;
   lps[0]=0;
   i=1;
   while(i<M)
   {
   	 if(pat[i]==pat[len])
   	 {
   	 	len++;
   	 	lps[i]=len;
   	 	i++;
   	 }
   	 else
   	 {
   	 	if(len!=0)
   	 	len = lps[len-1];
   	 	else
   	 	{
   	 		lps[i]=0;
   	 		i++;
   	 	}
   	 }
   }
} 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} 
//me'
#include <iostream>
using namespace std;
void compute(string p,int lps[])
{
  int i=1,j=0,k,l,len=0;
  lps[0]=0;
  int m = p.size();
  while(i<m)
  {
    if(p[i]==p[len])
    {
      len++;
      lps[i]=len;
      i++;
    }
    else
    {
      if(len!=0)
      len=lps[len-1];
      else
      {
        lps[i]=0;
        i++;
      }
    }
  }
}
void kmpsearch(string s,string p)
{
  int n =  s.size();
  int m = p.size();
  int lps[m];
  compute(p,lps);
  // cout<<"printing lps ar"<<endl;
  // for(int i=0;i<m;i++)
  // cout<<lps[i]<<" ";
  cout<<endl;
  int i=0,j=0,k,l;
  while(i<n)
  {
    if(p[j]==s[i])a
    {
      // cout<<"i= "<<i<<" j="<<j<<endl;
      i++;
      j++;
    }
    if(j==m)
    {
      cout<<"pat found at "<<i-j<<endl;
      j=lps[j-1];
    }
    else if(i<n&&p[j]!=s[i])
    {
      if(j!=0)
      j=lps[j-1];
      else
      i++;
    }
  }
}
int main() {
  string s = "ABABDABACDABABCABAB"; 
    string p = "ABABCABAB"; 
    kmpsearch(s, p); 
    return 0; 
  // your code goes here
  // return 0;
}