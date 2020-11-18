#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,k,cnt=0;
void makeboard(char **board)
{
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
		board[i][j] = '_';
	}
}
void dispboard(char **board)
{
	for(ll i=0;i<m;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}
void attack(char a,ll i,ll j,char **board)
{
	if ((i + 2) < m && (j - 1) >= 0) { 
        board[i + 2][j - 1] = a; 
    } 
    if ((i - 2) >= 0 && (j - 1) >= 0) { 
        board[i - 2][j - 1] = a; 
    } 
    if ((i + 2) < m && (j + 1) < n) { 
        board[i + 2][j + 1] = a; 
    } 
    if ((i - 2) >= 0 && (j + 1) < n) { 
        board[i - 2][j + 1] = a; 
    } 
    if ((i + 1) < m && (j + 2) < n) { 
        board[i + 1][j + 2] = a; 
    } 
    if ((i - 1) >= 0 && (j + 2) < n) { 
        board[i - 1][j + 2] = a; 
    } 
    if ((i + 1) < m && (j - 2) >= 0) { 
        board[i + 1][j - 2] = a; 
    } 
    if ((i - 1) >= 0 && (j - 2) >= 0) { 
        board[i - 1][j - 2] = a; 
    }
}
bool canplace(ll i,ll j,char **board)
{
	if(board[i][j]=='_')
	return true;
	else
	return false;
}
void place(char k,char a,char **board,char **newboard,ll i,ll j)
{
	for(ll x=0;x<m;x++)
	for(ll y=0;y<n;y++)
	newboard[x][y] = board[x][y];
	newboard[i][j] = k;
	attack(a,i,j,newboard);
}

void kkn(ll sti,ll stj,char **board,ll k)
{
	if(k==0)// no knight left
	{
	  dispboard(board);
	  cnt++;
	  //return;
	}
	else
	{
		ll i,j,p;
		for(i=sti;i<m;i++)
		{
			for(j=stj;j<n;j++)
			{
				if(canplace(i,j,board))
				{
					char **newboard = new char*[m];
					for(ll x=0;x<m;x++)
					newboard[x] = new char[n];
					place('K','A',board,newboard,i,j);
					/* Call the function recursively for 
                      (k-1) leftover knights */
                    kkn(i, j, newboard,k-1); 
                    /* Delete the new board  
                    to free up the memory */
                    for (int x = 0; x < m; x++) { 
                        delete[] newboard[x]; 
                    } 
                    delete[] newboard; 
				}
			}
			stj = 0;
		}
	}
	
}
int main() {
	m = 4, n = 3, k = 6; 
  
    /* Creation of a m*n board */
    char** board = new char*[m]; 
    for (int i = 0; i < m; i++) { 
        board[i] = new char[n]; 
    } 
  
    /* Make all the places are empty */
    makeboard(board); 
  
    kkn(0, 0, board,k); 
  
    cout << endl 
         << "Total number of solutions : "
         << cnt; 
    return 0;
}