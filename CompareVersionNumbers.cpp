//THIS IS IB SOL IF NUMBER FORMAT OF VERSION NUMBERS GOES OU OF BOUNDS
int cmp1(string s1,string s2)
{   
    while(s1[0]=='0')
    {
        s1.erase(0,1);
    }
    while(s2[0]=='0')
    {
        s2.erase(0,1);
    }
    if(s1.size()>s2.size())
    return 1;
    if(s2.size()>s1.size())
    return -1;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>s2[i])
        return 1;
        if(s2[i]>s1[i])
        return -1;
    }
    return 0;
    
}
int Solution::compareVersion(string A, string B) {
   int k=0;
    vector<string>a,b;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='.')
        {
            string p1=A.substr(k,(i-k));
       
            k=i+1;
            a.push_back(p1);
        }
    }
    a.push_back(A.substr(k,(A.size()-k)));
    k=0;
      for(int i=0;i<B.size();i++)
    {
        if(B[i]=='.')
        {
            string p1=B.substr(k,(i-k));
            
            b.push_back(p1);
        }
    }
    b.push_back(B.substr(k,(B.size()-k)));
    int dif=abs(a.size()-b.size());
    if(a.size()>b.size())
    {
        for(int i=1;i<=dif;i++)
        b.push_back("0");
    }
    else if(b.size()>a.size())
    {
        for(int i=1;i<=dif;i++)
        a.push_back("0");
    }
    for(int i=0;i<a.size();i++)
    {
       
      if(cmp1(a[i],b[i])==1)
      return 1;
      if(cmp1(a[i],b[i])==-1)
      return -1;
      else
      continue;
    }
   
    return 0;
}
// THIS IS GFG SOL
// C/C++ program to compare two version number 
#include <bits/stdc++.h> 
using namespace std; 

// Method to compare two versions. Returns 1 if v2 is 
// smaller, -1 if v1 is smaller, 0 if equal 
int versionCompare(string v1, string v2) 
{ 
    // vnum stores each numeric part of version 
    int vnum1 = 0, vnum2 = 0; 

    // loop untill both string are processed 
    for (int i=0,j=0; (i<v1.length() || j<v2.length()); ) 
    { 
        // storing numeric part of version 1 in vnum1 
        while (i < v1.length() && v1[i] != '.') 
        { 
            vnum1 = vnum1 * 10 + (v1[i] - '0'); 
            i++; 
        } 

        // storing numeric part of version 2 in vnum2 
        while (j < v2.length() && v2[j] != '.') 
        { 
            vnum2 = vnum2 * 10 + (v2[j] - '0'); 
            j++; 
        } 

        if (vnum1 > vnum2) 
            return 1; 
        if (vnum2 > vnum1) 
            return -1; 

        // if equal, reset variables and go for next numeric 
        // part 
        vnum1 = vnum2 = 0; 
        i++; 
        j++; 
    } 
    return 0; 
} 

// Driver method to check above comparison function 
int main() 
{ 
    string version1 = "1.0.3"; 
    string version2 = "1.0.7"; 

    if (versionCompare(version1, version2) < 0) 
        cout << version1 << " is smaller\n"; 
    else if (versionCompare(version1, version2) > 0) 
        cout << version2 << " is smaller\n"; 
    else
        cout << "Both version are equal\n"; 
    return 0; 
} 
