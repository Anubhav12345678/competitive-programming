vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend()); //sorting both the lists in descending order.
    priority_queue<pair<int, pair<int, int>>> maxh; //max heap for storing (sum, (i - index, j - index))

    for (int i = 0; i < C; i++) //pushing the heads of all the linked lists.
    {
        maxh.push(make_pair(B[0] + A[i], make_pair(0, i)));
    }

    std::vector<int> ans;
    while(ans.size() < C)
    {
        auto maxele = maxh.top(); maxh.pop(); 
        ans.emplace_back(maxele.first); //pushing the top to ans and inserting head -> next.
        maxh.push(make_pair(B[maxele.second.first + 1] + A[maxele.second.second], make_pair(maxele.second.first + 1, maxele.second.second)));
    }
    return ans;
}
/*
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 103

1 <= C <= N




*/