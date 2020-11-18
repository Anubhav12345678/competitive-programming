class Solution {
    // priority_queue O(NlogN)
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i,j,k,l,n=stations.size();
        int cur=startFuel;
        i=0;
        priority_queue<int> pq;
        int res=0;
        for(res=0;cur<target;res++)
        {
            while(i<n&&stations[i][0]<=cur)
                pq.push(stations[i++][1]);
            if(pq.empty()) return -1;
            cur+=pq.top();
            pq.pop();
        }
        return res;
    }
};







// DP O(N^2) sol


class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int N = stations.length;
        //dp[t] means the furthest distance that we can get with t times of refueling.
        long[] dp = new long[N + 1];
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i)
            for (int t = i; t >= 0; --t)
                if (dp[t] >= stations[i][0])
                    dp[t+1] = Math.max(dp[t+1], dp[t] + (long) stations[i][1]);

        for (int i = 0; i <= N; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
}
/*

A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

*/