class Solution {
public:
   int minInsertions(string s) {
       int manual_add = 0;
       int req_close = 0;
       
       for (int i=0;i<s.length();i++) {
           // we see an opening bracket
           if (s[i] == '(') {
               // increment closed req by 2
               req_close += 2;
               if (req_close%2 != 0) {
                   // if total is odd, we do the steps as explained above.
                   manual_add++;
                   req_close--;
               }
           } else {
               // we see a closing bracket
               
               if (req_close == 0) {
                   // lone warrior \*o*/
                   manual_add++;
                   req_close++;
               } else  {
                   req_close--;
               }
           }
       }
       return manual_add + req_close;
   }
};
/*

Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

 

Example 1:

Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching.
 We need to to add one more ')' at the end of the string to be "(())))" which is balanced.
*/