vector<vector<string>> ans;
 
void solveNQueen(vector<string> &board, vector<bool> &col, vector<bool> &pd, vector<bool> &nd, int A, int row) {
    //row has reached till end --> valid configuration achieved
    //push to answer
    if(row == A) {
        ans.push_back(board);
        return ;
    }
    
    //recursive case
    for(int c=0; c<A; c++) {
        //check whether the cell is unmarked
        //if yes --> place a Q there and move to next row
        //if no --> move to next column in the same row and repeat
        if((col[c] == 0) && (pd[row+c] == 0) && (nd[row-c+A-1] == 0)) {
            board[row][c] = 'Q';
            col[c] = pd[row+c] = nd[row-c+A-1] = 1;
            solveNQueen(board, col, pd, nd, A, row+1);
            board[row][c] = '.';
            col[c] = pd[row+c] = nd[row-c+A-1] = 0;
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    ans.clear();
    // vector<string> board;
    vector<bool> col(A,0);
    vector<bool> pd(2*A-1,0);
    vector<bool> nd(2*A-1,0);
    int i=A;
    string tmp;
    tmp.clear();
    while(i--)
    tmp.push_back('.');
    vector<string> board(A,tmp);
    solveNQueen(board,col,pd,nd,A,0);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
/* C/C++ program to solve N Queen Problem using 
backtracking */
#include<bits/stdc++.h> 
#define N 4 

/* A utility function to print solution */
void printSolution(int board[N][N]) 
{ 
    static int k = 1; 
    printf("%d-\n",k++); 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
    printf("\n"); 
} 

/* A utility function to check if a queen can 
be placed on board[row][col]. Note that this 
function is called when "col" queens are 
already placed in columns from 0 to col -1. 
So we need to check only left side for 
attacking queens */
bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 

    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 

    return true; 
} 

/* A recursive utility function to solve N 
Queen problem */
bool solveNQUtil(int board[N][N], int col) 
{ 
    /* base case: If all queens are placed 
    then return true */
    if (col == N) 
    { 
        printSolution(board); 
        return true; 
    } 

    /* Consider this column and try placing 
    this queen in all rows one by one */
    bool res = false; 
    for (int i = 0; i < N; i++) 
    { 
        /* Check if queen can be placed on 
        board[i][col] */
        if ( isSafe(board, i, col) ) 
        { 
            /* Place this queen in board[i][col] */
            board[i][col] = 1; 

            // Make result true if any placement 
            // is possible 
            res = solveNQUtil(board, col + 1) || res; 

            /* If placing queen in board[i][col] 
            doesn't lead to a solution, then 
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK 
        } 
    } 

    /* If queen can not be place in any row in 
        this column col then return false */
    return res; 
} 

/* This function solves the N Queen problem using 
Backtracking. It mainly uses solveNQUtil() to 
solve the problem. It returns false if queens 
cannot be placed, otherwise return true and 
prints placement of queens in the form of 1s. 
Please note that there may be more than one 
solutions, this function prints one of the 
feasible solutions.*/
void solveNQ() 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 

    if (solveNQUtil(board, 0) == false) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 

    return ; 
} 

// driver program to test above function 
int main() 
{ 
    solveNQ(); 
    return 0; 
} 
