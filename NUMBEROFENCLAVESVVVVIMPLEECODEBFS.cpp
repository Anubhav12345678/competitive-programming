/*

Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.



*/


int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
class Solution {
public:
   
    queue<pair<int,int> > q;
    void walk(int a,int b,vector<vector<int> > &A){
        q.push(make_pair(a,b));
        A[a][b]=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&yy>=0&&xx<A.size()&&yy<A[i].size()){
                    if(A[xx][yy]==1){
                        A[xx][yy]=0;
                        q.push(make_pair(xx,yy));
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==1){
                    if(i==0||j==0||i==A.size()-1||j==A[i].size()-1){
                        walk(i,j,A);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){ 
                if(A[i][j]==1){
                  cnt++;  
                }
            }
        }
        return cnt;
    }
};
