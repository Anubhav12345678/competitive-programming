/*

Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.

 

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.
Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".
Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.
Example 4:

Input: croakOfFrogs = "croakcroa"
Output: -1


*/



class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> v(5);
        for (char i : croakOfFrogs)
            if (i == 'c')
                v[0]++, v[4] = max(0, v[4] - 1);
            else if (i == 'r')
                if (v[0])
                    v[0]--, v[1]++;
                else
                    return -1;
            else if (i == 'o')
                if (v[1])
                    v[1]--, v[2]++;
                else
                    return -1;
            else if (i == 'a')
                if (v[2])
                    v[2]--, v[3]++;
                else
                    return -1;
            else if (i == 'k')
                if (v[3])
                    v[3]--, v[4]++;
                else
                    return -1;
        if (v[0] || v[1] || v[2] || v[3])
            return -1;
        return v[4];
    }
};