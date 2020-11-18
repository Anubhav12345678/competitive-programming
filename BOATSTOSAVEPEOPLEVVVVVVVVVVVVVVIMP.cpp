class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i,j,k,l,n=people.size();
        int ans=0;
        sort(people.begin(),people.end());
        i=0;
        j=n-1;
        while(i<=j)
        {
            ans++;
            if((people[i]+people[j])<=limit)
                i++;
            j--;
        }
        return ans; 
            
    }
};
/*
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)




*/