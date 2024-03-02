class Solution {
public:
    int solve(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp, int n){
        if(ind >= n) return 0;
        if(cap == 0) return 0;
        if(dp[ind][buy][cap] != -1)  return dp[ind][buy][cap];
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + solve(ind + 1, 0, cap, prices, dp, n), solve(ind + 1, 1, cap, prices, dp, n));
        } 
        else {
            profit = max(prices[ind] + solve(ind + 1, 1, cap - 1, prices, dp, n), 0 + solve(ind + 1, 0, cap, prices, dp, n));
        }
         return dp[ind][buy][cap] = profit;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0,1,2, prices, dp, n);

    }
};