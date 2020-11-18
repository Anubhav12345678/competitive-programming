void solve(string a,vector<string> &b,string prev,vector<string> &op){
    if(a=="")
    {
        op.push_back(prev);
        return;
    }
    for(int i=0;i<a.size();i++){
        string n = a.substr(0,i+1);
        if(find(b.begin(),b.end(),n)!=b.end()){
            string next = a.substr(i+1);
            string prev_new;
            if(prev=="")
            prev_new = n;
            else
            prev_new = prev+" "+n;
            solve(next,b,prev_new,op);
        }
    }
    
}

vector<string> Solution::wordBreak(string a, vector<string> &b) {
              vector<string> op;
              solve(a,b,"",op);
              return op;
}




//gvn string and dictionary of words determine if strings can be segmented into a space seperated sequnece of one or more dict words




//USING DPVVVVVVVIMP
// A Dynamic Programming based program to test whether a given string can 
// be segmented into space separated words in dictionary 
#include <iostream> 
#include <string.h> 
using namespace std; 

/* A utility function to check whether a word is present in dictionary or not. 
An array of strings is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango", 
						"icecream","and","go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// Returns true if string can be segmented into space separated 
// words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 
	if (size == 0) return true; 

	// Create the DP table to store results of subroblems. The value wb[i] 
	// will be true if str[0..i-1] can be segmented into dictionary words, 
	// otherwise false. 
	bool wb[size+1]; 
	memset(wb, 0, sizeof(wb)); // Initialize all values as false. 

	for (int i=1; i<=size; i++) 
	{ 
		// if wb[i] is false, then check if current prefix can make it true. 
		// Current prefix is "str.substr(0, i)" 
		if (wb[i] == false && dictionaryContains( str.substr(0, i) )) 
			wb[i] = true; 

		// wb[i] is true, then check for all substrings starting from 
		// (i+1)th character and store their results. 
		if (wb[i] == true) 
		{ 
			// If we reached the last prefix 
			if (i == size) 
				return true; 

			for (int j = i+1; j <= size; j++) 
			{ 
				// Update wb[j] if it is false and can be updated 
				// Note the parameter passed to dictionaryContains() is 
				// substring starting from index 'i' and length 'j-i' 
				if (wb[j] == false && dictionaryContains( str.substr(i, j-i) )) 
					wb[j] = true; 

				// If we reached the last character 
				if (j == size && wb[j] == true) 
					return true; 
			} 
		} 
	} 

	/* Uncomment these lines to print DP table "wb[]" 
	for (int i = 1; i <= size; i++) 
		cout << " " << wb[i]; */

	// If we have tried all prefixes and none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 





#include <bits/stdc++.h>
using namespace std;
#include<vector>
bool solve(vector<string> &dic,string str,vector<int> &lookup)
{
	int n = str.size();
	if(n==0)
	return 1;
	if(lookup[n]==-1)
	{
		lookup[n]=0;
		for(int i=1;i<=n;i++)
		{
			string p = str.substr(0,i);
			if(find(dic.begin(),dic.end(),p)!=dic.end()&&solve(dic,str.substr(i),lookup))
			return lookup[n]=1;
		}
	}
	retur lookup[n];
}
// Word Break Problem
int main()
{
	// vector of strings to represent dictionary
	// we can also use trie or std::set to store dictionary
	vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";

	// look-up array to store solutions to sub-problems
	// lookup[i] stores if substring str[n-i..n) can be segmented or not
	vector<int> lookup(str.length() + 1, -1);

	if (solve(dict, str, lookup))
		cout << "String can be segmented";
	else
		cout << "String can't be segmented";

	return 0;
}