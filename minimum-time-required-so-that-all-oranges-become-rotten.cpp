// C++ program to find minimum time required to make all 
// oranges rotten 
#include<bits/stdc++.h> 
#define R 3 
#define C 5 
using namespace std; 

// function to check whether a cell is valid / invalid 
bool isvalid(int i, int j) 
{ 
	return (i >= 0 && j >= 0 && i < R && j < C); 
} 

// structure for storing coordinates of the cell 
struct ele { 
	int x, y; 
}; 

// Function to check whether the cell is delimiter 
// which is (-1, -1) 
bool isdelim(ele temp) 
{ 
	return (temp.x == -1 && temp.y == -1); 
} 

// Function to check whether there is still a fresh 
// orange remaining 
bool checkall(int arr[][C]) 
{ 
	for (int i=0; i<R; i++) 
	for (int j=0; j<C; j++) 
		if (arr[i][j] == 1) 
			return true; 
	return false; 
} 

// This function finds if it is possible to rot all oranges or not. 
// If possible, then it returns minimum time required to rot all, 
// otherwise returns -1 
int rotOranges(int arr[][C]) 
{ 
	// Create a queue of cells 
	queue<ele> Q; 
	ele temp; 
	int ans = 0; 

	// Store all the cells having rotten orange in first time frame 
	for (int i=0; i<R; i++) 
	{ 
	for (int j=0; j<C; j++) 
	{ 
			if (arr[i][j] == 2) 
			{ 
				temp.x = i; 
				temp.y = j; 
				Q.push(temp); 
			} 
		} 
	} 

	// Separate these rotten oranges from the oranges which will rotten 
	// due the oranges in first time frame using delimiter which is (-1, -1) 
	temp.x = -1; 
	temp.y = -1; 
	Q.push(temp); 

	// Process the grid while there are rotten oranges in the Queue 
	while (!Q.empty()) 
	{ 
		// This flag is used to determine whether even a single fresh 
		// orange gets rotten due to rotten oranges in current time 
		// frame so we can increase the count of the required time. 
		bool flag = false; 

		// Process all the rotten oranges in current time frame. 
		while (!isdelim(Q.front())) 
		{ 
			temp = Q.front(); 

			// Check right adjacent cell that if it can be rotten 
			if (isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1) 
			{ 
				// if this is the first orange to get rotten, increase 
				// count and set the flag. 
				if (!flag) ans++, flag = true; 

				// Make the orange rotten 
				arr[temp.x+1][temp.y] = 2; 

				// push the adjacent orange to Queue 
				temp.x++; 
				Q.push(temp); 

				temp.x--; // Move back to current cell 
			} 

			// Check left adjacent cell that if it can be rotten 
			if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) { 
				if (!flag) ans++, flag = true; 
				arr[temp.x-1][temp.y] = 2; 
				temp.x--; 
				Q.push(temp); // push this cell to Queue 
				temp.x++; 
			} 

			// Check top adjacent cell that if it can be rotten 
			if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) { 
				if (!flag) ans++, flag = true; 
				arr[temp.x][temp.y+1] = 2; 
				temp.y++; 
				Q.push(temp); // Push this cell to Queue 
				temp.y--; 
			} 

			// Check bottom adjacent cell if it can be rotten 
			if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) { 
				if (!flag) ans++, flag = true; 
				arr[temp.x][temp.y-1] = 2; 
				temp.y--; 
				Q.push(temp); // push this cell to Queue 
			} 

			Q.pop(); 
		} 

		// Pop the delimiter 
		Q.pop(); 

		// If oranges were rotten in current frame than separate the 
		// rotten oranges using delimiter for the next frame for processing. 
		if (!Q.empty()) { 
			temp.x = -1; 
			temp.y = -1; 
			Q.push(temp); 
		} 

		// If Queue was empty than no rotten oranges left to process so exit 
	} 

	// Return -1 if all arranges could not rot, otherwise -1. 
	return (checkall(arr))? -1: ans; 
} 

// Drive program 
int main() 
{ 
	int arr[][C] = { {2, 1, 0, 2, 1}, 
					{1, 0, 1, 2, 1}, 
					{1, 0, 0, 2, 1}}; 
	int ans = rotOranges(arr); 
	if (ans == -1) 
		cout << "All oranges cannot rotn"; 
	else
		cout << "Time required for all oranges to rot => " << ans << endl; 
	return 0; 
} 


//me leetcode
class Solution {
public:
    struct ele
    {
        int x, y;
    };
    bool  isval(int i,int j,int r,int c)
    {
        return (i>=0&&j>=0&&i<r&&j<c);
            // return 1;
        // return 0;
    }
    bool isdelim(struct ele tmp)
    {
        return tmp.x==-1&&tmp.y==-1;
    }
    bool chkall(vector<vector<int>> &m)
    {
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<m[0].size();j++)
                if(m[i][j]==1)
                    return 1;
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<struct ele> q;
        struct ele tmp;
        tmp.x=-1;
        tmp.y=-1;
        int n=grid.size(),m  = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        q.push(tmp);
        int ans=0;
        while(!q.empty())
        {
            bool fg=0;
            while(!isdelim(q.front()))
            {
                tmp = q.front();
                if(isval(tmp.x+1,tmp.y,n,m)&&grid[tmp.x+1][tmp.y]==1)
                {
                    if(!fg) ans++,fg=1;
                    grid[tmp.x+1][tmp.y]=2;
                    q.push({tmp.x+1,tmp.y});
                }
                if(isval(tmp.x-1,tmp.y,n,m)&&grid[tmp.x-1][tmp.y]==1)
                {
                    if(!fg) ans++,fg=1;
                    grid[tmp.x-1][tmp.y]=2;
                    q.push({tmp.x-1,tmp.y});
                }
                if(isval(tmp.x,tmp.y+1,n,m)&&grid[tmp.x][tmp.y+1]==1)
                {
                    if(!fg) ans++,fg=1;
                    grid[tmp.x][tmp.y+1]=2;
                    q.push({tmp.x,tmp.y+1});
                }
                if(isval(tmp.x,tmp.y-1,n,m)&&grid[tmp.x][tmp.y-1]==1)
                {
                    if(!fg) ans++,fg=1;
                    grid[tmp.x][tmp.y-1]=2;
                    q.push({tmp.x,tmp.y-1});
                }
                q.pop();
            }
            q.pop();
            if(!q.empty())
            {
                q.push({-1,-1});
            }
            
        }
        return (chkall(grid))? -1:ans;
    }
};