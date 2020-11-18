class Solution {
public:
    /*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2


    */
    // both stack and dfs sol

    //stack sol
    class Solution {
public:
    int scoreOfParentheses(string s) {
        int i,j,k,l,n=s.size();
        stack<int> st;
        vector<int> score(n,0);
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);
            else{
                j=st.top();
                st.pop();
                if(j==i-1)
                    score[i]++;
                else{
                    for(k=j+1;k<i;k++)
                    {
                        score[i]+=score[k];
                        score[k]=0;
                    }
                    score[i]*=2;
                }
            }
            // cout<<"score["<<i<<"] = "<<score[i]<<endl;
        }
        return accumulate(score.begin(),score.end(),0);
    }
};


    //dfs
    int solve(string s,int i,int j)
    {
        int ans=0,bal=0;
        for(int k=i;k<j;k++)
        {
            bal+=(s[k]=='(')?1:-1;
            if(bal==0)
            {
                if(k-i==1)
                    ans++;
                else
                    ans+=2*solve(s,i+1,k);
                i=k+1;
            }
        }
        return ans;
    }
    int scoreOfParentheses(string S) {
        return solve(S,0,S.size());
    }
};