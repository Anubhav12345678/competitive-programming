vector<int> Solution::maxone(vector<int> &a, int k) {
    int i = 0 , j = 0 , ct = 0;
    int mx_len = 0 , len , startI;
    
    while(j<a.size())
    {
        if(a[j] == 0)
            ct++;
        while(ct > k)
            if(a[i++] == 0)
                ct--;
        len = j-i+1;
        if(len > mx_len )
            mx_len = len , startI = i;
        j++;
    }
    vector<int> ans(mx_len);
    for(auto &i:ans)
        i = startI++;
    return ans;
}
/*

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.


*/