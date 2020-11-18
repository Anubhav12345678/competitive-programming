

/*

Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
Seen this question in a real interview before



*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int i,j,k,l,n=A.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    set<pair<int,int>> s;
    int sum  =A[n-1]+B[n-1];
    pq.push(make_pair(sum,make_pair(n-1,n-1)));
    s.insert(make_pair(n-1,n-1));
    k=n;
    vector<int> res;
    while(k--)
    {
        pair<int,pair<int,int>> p= pq.top();
        pq.pop();
        res.push_back(p.first);
        int l = p.second.first;
        int r = p.second.second;
        if(l>=0&&r>0&&s.find({l,r-1})==s.end())
        {
            // res.push_back(A[l]+B[r-1]);
            pq.push(make_pair(A[l]+B[r-1],make_pair(l,r-1)));
            s.insert({l,r-1});
        }
        if(l>0&&r>=0&&s.find({l-1,r})==s.end())
        {
            // res.push_back(A[l-1]+B[r]);
            pq.push(make_pair(A[l-1]+B[r],make_pair(l-1,r)));
            s.insert({l-1,r});
        }
    }
    return res;
    
}
