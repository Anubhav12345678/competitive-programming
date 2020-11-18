
/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

*/




class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i,j,k,l,n=seats.size();
        int ans=0;
        int lastind=-1;
        for(i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                j=i+1;
                while(j<n&&seats[j]!=1)
                    j++;
                if(j==n)
                {
                    ans = max(ans,j-i-1);
                    break;
                }
                else
                {
                    ans = max(ans,(j-i)/2);
                    i=j-1;
                }
            }
            
        }
        
        for(i=n-1;i>=0;i--)
        {
             if(seats[i]==1)
            {
                j=i-1;
                while(j>=0&&seats[j]!=1)
                    j--;
                if(j==-1)
                {
                    ans = max(ans,i);
                    break;
                }
                else
                {
                    ans = max(ans,(i-j)/2);
                    i=j+1;
                }
            }
        }
        return ans;
    }
};