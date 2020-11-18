#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int dx[] = {-1 , -1 , -1, 0 , 0 , 1 , 1 , 1};// xdirection
int dy[] = {-1 , 0 , 1 , -1, 1 , -1, 0, 1};// ydirection
int row , col , x , y;
int pat[1001][1001];
bool visit[1001][1001];  
    
struct  Point{
  int x , y , d;
  Point(int a ,int b , int c){
    x = a , y = b , d = c;
    }
  };
 bool check(int x , int y){
  if(x < 0 || y < 0 || x >= row || y >= col || visit[x][y] == true){
    return false;
  }
  return true;
}
/*
You are required to form a matrix of size  where  is the number of rows and  is the number of columns. You are required to form the waves of numbers around the provided center,  (0-based indexing).

Example:

Size of the matrix:  and 
Center coordinates:  and  (0 based indexing)
Pattern:
            4 4 4 4 4 4 4 4 4 
            4 3 3 3 3 3 3 3 4 
            4 3 2 2 2 2 2 3 4 
            4 3 2 1 1 1 2 3 4 
            4 3 2 1 0 1 2 3 4 
            4 3 2 1 1 1 2 3 4 
            4 3 2 2 2 2 2 3 4 
            4 3 3 3 3 3 3 3 4 
            4 4 4 4 4 4 4 4 4

You are given the values of  (the values of  and  is 0-based indexed). Your task is to print the provided pattern.
*/
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    cin >> row >> col;
    cin >> x >> y;
    queue < Point > Q;
    Point p(x , y , 0) ;
    pat[x][y] = 0;
    Q.push(p);
    visit[x][y] = 1;
    while(Q.size() > 0){
      Point P = Q.front();
      Q.pop();
      int x = P.x;
      int y = P.y;
      int d = P.d;
      for(int i = 0 ; i < 8 ; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(check(X , Y)){    
          Point A(X , Y , d + 1); 
          visit[X][Y] = 1;
          pat[X][Y] = A.d;
          Q.push(A);
        }
      }
    }
    for(int i = 0 ; i < row ; i++){
      for(int j = 0 ; j < col ; j++){
        cout << pat[i][j] << " ";
      }
      cout << endl;
    }
  return 0;
}