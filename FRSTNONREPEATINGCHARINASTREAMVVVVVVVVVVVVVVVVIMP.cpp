string Solution::solve(string A) {
   string ans = "";
int m[26];
memset(m,0,sizeof(m));
queue<char> q;
int n = A.length();
for(int i=0;i<n;i++)
{
m[A[i] - 97]++;
q.push(A[i]);
while(!q.empty() && m[q.front() - 97] > 1)
q.pop();
if(q.empty()) ans += "#";
else ans += q.front();
}
return ans;
}
