class Solution {
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>>&dp, int fee){
    if(ind >= prices.size()) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy){
        return dp[ind][buy] = max(-prices[ind] + solve(ind+1, 0, prices, dp, fee) , 0+ solve(ind+1, 1, prices, dp, fee));

    }
        return dp[ind][buy] = max(prices[ind]-fee + solve(ind+1, 1, prices, dp, fee) , 0+ solve(ind+1, 0, prices, dp, fee));
    
}
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(0,1,prices, dp, fee);
    }
};