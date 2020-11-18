

/*

Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 

Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: A = 4, B = 1
Output: "aabaa"



*/



class Solution {
public:
    string strWithout3a3b(int A, int B) {
                string s;
        int i=A,j=B,k,l;
        int cont=0;
        char last=' ';
       while(A>0||B>0)
       {
           if((A>=B&&(last!='a'||cont<2))||(last=='b'&&cont>=2))
           {
               s+='a';
               --A;
               if(last=='a') cont++;
               else last='a', cont=1;
           }
           else
           {
               --B;
               s+='b';
               if(last=='b') cont++;
               else last='b', cont=1;
           }
       }
    }
};