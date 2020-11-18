

//LEETCODE BETTER
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(!n)
            return 1;
        int i,j,k,l;
        int dp[n+1];
        dp[n]=1;
        if(s[n-1]=='0')
            dp[n-1]=0;
        else
            dp[n-1]=1;
        for(i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
                dp[i]=0;
            else if(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))
                dp[i]=dp[i+1]+dp[i+2];
            else
                dp[i] = dp[i+1];
        }
        return dp[0];
    }
};






// A naive recursive C++ implementation to count number of decodings 
// that can be formed from a given digit sequence 
#include <iostream> 
#include <cstring> 
using namespace std; 

// Given a digit sequence of length n, returns count of possible 
// decodings by replacing 1 with A, 2 woth B, ... 26 with Z 
int countDecoding(char *digits, int n) 
{ 
	// base cases 
	if (n == 0 || n == 1) 
		return 1; 

	int count = 0; // Initialize count 

	// If the last digit is not 0, then last digit must add to 
	// the number of words 
	if (digits[n-1] > '0') 
		count = countDecoding(digits, n-1); 

	// If the last two digits form a number smaller than or equal to 26, 
	// then consider last two digits and recur 
	if (digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7') ) 
		count += countDecoding(digits, n-2); 

	return count; 
} 

// Driver program to test above function 
int main() 
{ 
	char digits[] = "1234"; 
	int n = strlen(digits); 
	cout << "Count is " << countDecoding(digits, n); 
	return 0; 
} 
