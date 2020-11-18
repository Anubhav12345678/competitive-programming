
/*

S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted.
 More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.





*/





class Solution {
public:
    string customSortString(string S, string T) {
        int i,j,k,l;
        int index=0;
        for(i=0;i<S.size();i++)
        {
            for(j=index;j<T.size();j++)
            {
                if(T[j]==S[i])
                {
                    swap(T[index],T[j]);
                    index++;
                }
            }
        }
        return T;
    }
};