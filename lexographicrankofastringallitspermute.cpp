// C++ program to print rank of 
// string using next_permute() 
#include <bits/stdc++.h> 
using namespace std; 
// lexographic rank of a string using stl
// Function to print rank of string 
// using next_permute() 
int findRank(string str) 
{ 
	// store original string 
	string orgStr = str; 

	// Sort the string in lexicographically 
	// ascending order 
	sort(str.begin(), str.end()); 

	// Keep iterating until 
	// we reach equality condition 
	long int i = 1; 
	do { 
		// check for nth iteration 
		if (str == orgStr) 
			break; 

		i++; 
	} while (next_permutation(str.begin(), str.end())); 

	// return iterator value 
	return i; 
} 

// Driver code 
int main() 
{ 
	string str = "GEEKS"; 
	cout << findRank(str); 
	return 0; 
} 

// lexographic rank of a string withou using fun in O(n^2)
// C++ program to find lexicographic rank 
// of a string 
#include <bits/stdc++.h> 
#include <string.h> 

using namespace std; 
// A utility function to find factorial of n 
int fact(int n) 
{ 
	return (n <= 1) ? 1 : n * fact(n - 1); 
} 

// A utility function to count smaller characters on right 
// of arr[low] 
int findSmallerInRight(char* str, int low, int high) 
{ 
	int countRight = 0, i; 

	for (i = low + 1; i <= high; ++i) 
		if (str[i] < str[low]) 
			++countRight; 

	return countRight; 
} 

// A function to find rank of a string in all permutations 
// of characters 
int findRank(char* str) 
{ 
	int len = strlen(str); 
	int mul = fact(len); 
	int rank = 1; 
	int countRight; 

	int i; 
	for (i = 0; i < len; ++i) { 
		mul /= len - i; 

		// count number of chars smaller than str[i] 
		// fron str[i+1] to str[len-1] 
		countRight = findSmallerInRight(str, i, len - 1); 

		rank += countRight * mul; 
	} 

	return rank; 
} 

// Driver program to test above function 
int main() 
{ 
	char str[] = "string"; 
	cout << findRank(str); 
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai 


//lexographic rank of a string withou using fun in O(n)
// A O(n) solution for finding rank of string 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX_CHAR 256 

// A utility function to find factorial of n 
int fact(int n) 
{ 
	return (n <= 1) ? 1 : n * fact(n - 1); 
} 

// Construct a count array where value at every index 
// contains count of smaller characters in whole string 
void populateAndIncreaseCount(int* count, char* str) 
{ 
	int i; 

	for (i = 0; str[i]; ++i) 
		++count[str[i]]; 

	for (i = 1; i < MAX_CHAR; ++i) 
		count[i] += count[i - 1]; 
} 

// Removes a character ch from count[] array 
// constructed by populateAndIncreaseCount() 
void updatecount(int* count, char ch) 
{ 
	int i; 
	for (i = ch; i < MAX_CHAR; ++i) 
		--count[i]; 
} 

// A function to find rank of a string in all permutations 
// of characters 
int findRank(char* str) 
{ 
	int len = strlen(str); 
	int mul = fact(len); 
	int rank = 1, i; 

	// all elements of count[] are initialized with 0 
	int count[MAX_CHAR] = { 0 }; 

	// Populate the count array such that count[i] 
	// contains count of characters which are present 
	// in str and are smaller than i 
	populateAndIncreaseCount(count, str); 

	for (i = 0; i < len; ++i) { 
		mul /= len - i; 

		// count number of chars smaller than str[i] 
		// fron str[i+1] to str[len-1] 
		rank += count[str[i] - 1] * mul; 

		// Reduce count of characters greater than str[i] 
		updatecount(count, str[i]); 
	} 

	return rank; 
} 

// Driver program to test above function 
int main() 
{ 
	char str[] = "string"; 
	cout << findRank(str); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 




// THIS IS FROM IB IMP THIS IS FOR LARGE TEST CASES
long long int fact(int n)
{
    return (n<=1)?1:(n*fact(n-1)%1000003)%1000003;
}
void populate(int cnt[],string s)
{
    int i,j,k;
    for(i=0;i<s.size();i++)
    cnt[s[i]]++;
    for(i=1;i<256;i++)
    cnt[i]+=cnt[i-1];
}
void update(int cnt[],char c)
{
    int i;
    for(i=c;i<256;i++)
    --cnt[i];
}
// int cntthe(string s,int low,int high)
// {
//     char c = s[low];
//     int i,j,count=0;
//     for(i=low+1;i<=high;i++)
//     if(s[i]<c)
//     count++;
//     return count;
// }
int Solution::findRank(string A) {
    
    int n = A.size();
    int i,j,k;
    int cnt[256] = {0};
    populate(cnt,A);
    long long int mul = fact(n);
    long long int rank = 1;
    long long int f=1;
    for(i=0;i<n;i++)
    {
        f = fact(n-i-1);
        // mul/=(n-i);
        // k = cntthe(A,i,n-1);
        // rank+=k*mul;
        rank+=((cnt[A[i]-1])%1000003*(f)%1000003)%1000003;
        update(cnt,A[i]);
    }
    return rank%1000003;
    // int i =1;
    // string org = A;
    // sort(A.begin(),A.end());
    // do{
    //     if(A==org)
    //     break;
    //     i++;
    // }while(next_permutation(A.begin(),A.end()));
    // return i;
}


























































