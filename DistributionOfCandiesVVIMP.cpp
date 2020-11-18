class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n= num_people;
        long long int i=-1,j,k=1,l;
        vector<int> res(n,0);
        while(candies>0)
        {
            i=(i+1)%n;
            if(candies<=k)
            {
                res[i]+=candies;
                break;
            }
            else
            {
                res[i]+=k;
                candies-=k;
                k++;
            }
        }
        return res;
    }
};