class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int i,j,k,l,n=prices.size();
        if(n<2) return 0;
        vector<int> stock(n);// stock[i] = max profit having stock on ith day
        vector<int> cash(n);// cash[i] = max profit without having stock on ith day
        stock[0]= -prices[0];
        cash[0]=0;
        for(i=1;i<n;i++){
            stock[i]  =max(stock[i-1],cash[i-1]-prices[i]);
            cash[i] = max(cash[i-1],stock[i-1]+prices[i]-fee);
        }
        return cash.back();
    }
};
/*
Your are given an array of integers prices, for which the i-th element is the price of a
 given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee 
for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.


*/