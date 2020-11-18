/*

There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.

*/



class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i,j,k,l,n=rooms.size();
        if(n==1)
            return 1;
        bool vis[n];
        memset(vis,0,sizeof(vis));
        // vis[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(vis[x])
                continue;
            vis[x]=1;
            for(i=0;i<rooms[x].size();i++)
                if(!vis[rooms[x][i]])
                    q.push(rooms[x][i]);
        }
        for(i=0;i<n;i++)
            if(!vis[i])
                break;
        return i==n;
    }
};