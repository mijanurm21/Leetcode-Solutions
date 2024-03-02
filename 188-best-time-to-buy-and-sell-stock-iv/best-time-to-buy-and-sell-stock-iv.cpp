class Solution {
public:
    int solve(int ind, int cap, vector<int>& prices, vector<vector<int>>&dp, int k){

        if(ind >= prices.size() || cap == 2*k) return 0;
        if(dp[ind][cap] != -1) return dp[ind][cap];
        int profit = 0;
        if(cap % 2== 0) {
            profit =  max(-prices[ind] + solve(ind+1, cap+1, prices, dp, k), solve(ind+1, cap, prices, dp,k) );
        }
        else{
            profit = max(prices[ind] + solve(ind+1, cap+1, prices, dp, k), solve(ind+1, cap, prices,dp, k) );
        }
        return dp[ind][cap] = profit;
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k,-1));
        return solve(0, 0, prices, dp, k);
    }
};