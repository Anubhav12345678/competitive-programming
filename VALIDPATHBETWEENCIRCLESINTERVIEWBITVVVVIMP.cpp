static int dx[8] = {-1,1,-1,1,0,0,-1,1};
static int dy[8] = {1,1,-1,-1,-1,1,0,0};
/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are 
inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching
 any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle
 at any point of time.
*/
bool isval(int a,int b,int A,int B){
    return a>=0&&b>=0&&a<=A&&b<=B;
}

bool incircle(int a,int b,int n,int r,vector<int> &xa,vector<int> &ya){
    for(int i=0;i<n;i++){
        if(((a-xa[i])*(a-xa[i])+(b-ya[i])*(b-ya[i]))<=r*r)
        return true;
    }
    return false;
}

string Solution::solve(int x, int y, int nc, int r, vector<int> &xa, vector<int> &ya) {
    int i,j,k,l,m,p;
     if(incircle(0,0,nc,r,xa,ya))
     return "NO";
     
     queue<pair<int,int>> q;
     q.push({0,0});
     bool vis[x+1][y+1];
     memset(vis,false,sizeof(vis));
     vis[0][0]=1;
     
     while(!q.empty()){
         int xi = q.front().first;
         int yi = q.front().second;
         q.pop();
         for(i=0;i<8;i++){
             int nx = xi+dx[i];
             int ny = yi+dy[i];
             if(isval(nx,ny,x,y)&&!vis[nx][ny]&&!incircle(nx,ny,nc,r,xa,ya))
             {
                 vis[nx][ny]=1;
                 q.push({nx,ny});
             }
         }
     }
     if(vis[x][y]) return "YES";
     else
     return "NO"; 
     
    
}
