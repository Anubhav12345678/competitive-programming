static int MOD=1e9+7;
class Solution {
public:
    /*
Given a rectangular pizza represented as a rows x cols matrix containing the following characters:
 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the
 cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part
  of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to 
  a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. 
Since the answer can be a huge number, return this modulo 10^9 + 7.
    */
    vector<vector<vector<int>>> memo;
    bool leftBoundaryContains(vector<string>& pizza,int col,int top)		//Check if left piece contains an apple
    {
        for(int i=top;i<pizza.size();i++)
            if(pizza[i][col]=='A')
                return true;
        return false;
    }
    bool topBoundaryContains(vector<string>& pizza,int left,int row)	//Check if top piece contains an apple
    {
        for(int i=left;i<pizza[0].size();i++)
            if(pizza[row][i]=='A')
                return true;
        return false;
    }
    int dp(vector<string>& pizza,int left,int top,int k)
    {
        if(memo[top][left][k]!=-1)
            return memo[top][left][k];
        if(k==1)		//Return 1 if the last piece left contains apple else 0.
        {
            for(int i=top;i<pizza.size();i++)
                for(int j=left;j<pizza[0].size();j++)
                    if(pizza[i][j]=='A')
                        return 1;
            return 0;
        }
        memo[top][left][k]=0;
        bool leftContains=false,topContains=false;	//These flags make the solution smater by skipping rechecking larger pieces whose smaller ones have appples.
        for(int c=left;c<pizza[0].size()-1;c++)		 //Move the left boundary till the last column (excluding the last column)
            if(leftContains||leftBoundaryContains(pizza,c,top))
            {
                leftContains=true;			//Mark that left piece will always contain apple from now on.
                memo[top][left][k]=(memo[top][left][k]+dp(pizza,c+1,top,k-1))%MOD;
                
            }
        for(int r=top;r<pizza.size()-1;r++)			 //Move the top boundary till the last row (excluding the last row)
            if(topContains||topBoundaryContains(pizza,left,r))
            {
                topContains=true;			//Mark that top piece will always contain apple from now on.
                memo[top][left][k]=(memo[top][left][k]+dp(pizza,left,r+1,k-1))%MOD;
                
            }
        return memo[top][left][k];
    }
    int ways(vector<string>& pizza, int k) 
    {
        memo.resize(pizza.size(),vector<vector<int>>(pizza[0].size(),vector<int>(k+1,-1)));
        return dp(pizza,0,0,k);
    }
};



// also me :)
static int mod=1e9+7;
#define ll long long
class Solution {
public:
    int memo[55][55][15];
    bool hasonleft(vector<string> &p,int col,int top){
        for(int i=top;i<p.size();i++)
            if(p[i][col]=='A') return true;
        return false;
    }
    
    bool hasontop(vector<string> &p,int row,int left){
        for(int i=left;i<p[0].size();i++)
            if(p[row][i]=='A') return true;
        return  false;
    }
    int solve(vector<string> &p,int  top,int left,int k){
        if(memo[top][left][k]!=-1) return memo[top][left][k];
        if(k==1){
            for(int i=top;i<p.size();i++){
                for(int j=left;j<p[0].size();j++)
                    if(p[i][j]=='A') return 1;
            }
            
            return 0;
        }
        memo[top][left][k]=0;
        bool toptrue=0;
        bool lefttrue=0;
        for(int c=left;c<p[0].size();c++){
            if(lefttrue||hasonleft(p,c,top)){
                lefttrue=true;
                memo[top][left][k] = (memo[top][left][k]+solve(p,top,c+1,k-1))%mod;
            }
        }
        
        for(int r=top;r<p.size();r++){
            if(toptrue||hasontop(p,r,left))
            {
                toptrue=true;
                memo[top][left][k] = (memo[top][left][k]+solve(p,r+1,left,k-1))%mod;
            }
        }
        
        return memo[top][left][k]%mod;
        
        
    }
    int ways(vector<string>& pizza, int k) {
        memset(memo,-1,sizeof(memo));
        return solve(pizza,0,0,k);
    }
};