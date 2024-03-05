class Solution {
public:
int solve(int ind, int buy, vector<int> &prices, vector<vector<int>>&dp){
    if(ind >= prices.size()) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy){
        return dp[ind][buy] = max(-prices[ind] + solve(ind+1, 0, prices, dp) , 0+ solve(ind+1, 1, prices, dp));

    }
        return dp[ind][buy] = max(prices[ind] + solve(ind+2, 1, prices, dp) , 0+ solve(ind+1, 0, prices, dp));

    
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(3,0));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<2; buy++){
                if(buy){
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0] , 0+ dp[ind+1][1]);

                }
                else dp[ind][buy] = max(prices[ind] + dp[ind+2][1] , 0+ dp[ind+1][0]);

            }
        }
        
        // return solve(0,1,prices, dp);
        return dp[0][1];
    }
};