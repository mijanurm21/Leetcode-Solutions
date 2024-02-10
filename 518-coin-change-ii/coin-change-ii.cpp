class Solution {
public:
    int solve(vector<int>a , int n, int val, vector<vector<int>> &dp){
        if(n == 0) {
            return (val % a[0]) == 0;
        }

        if(dp[n][val] != -1) return dp[n][val];
        int notake = solve(a, n-1, val, dp);
        int take = 0;
        if(a[n] <= val) take = solve(a, n, val - a[n], dp);
        return dp[n][val] = notake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, n-1, amount, dp);
    }
};