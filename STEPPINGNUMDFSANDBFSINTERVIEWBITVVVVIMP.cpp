/*

Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 

*/

//BFS
vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    if(A <= 0) ans.push_back(0);

    queue<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    while(nums.front() <= B){
        int i = nums.front();
        nums.pop();
        if(i >= A) ans.push_back(i);
        
        int lastd = i%10;
        if(lastd>0) nums.push(i*10+(lastd-1));
        if(lastd<9) nums.push(i*10+(lastd+1));
    }
    
    return ans;
}

//DFS
vector<int> sol;
void solve(int A,int B,long long int num)
{
    if(num>B)
    return;
    int rem=num%10;
    if(num>=A)
    sol.push_back(num);
    if(rem==0)
    solve(A,B,num*10+1);
    else if(rem==9)
    solve(A,B,num*10+8);
    else
    {
        solve(A,B,num*10+(rem-1));
        solve(A,B,num*10+(rem+1));
    }
}
vector<int> Solution::stepnum(int A, int B) {
    sol.clear();
    if(A>B)
    return sol;
    if(A==0)
    sol.push_back(0);
    for(int i=1;i<10;i++)
    {
        solve(A,B,(long long int)i);
    }
    if(sol.size())
    sort(sol.begin(),sol.end());
    return sol;
    
}
