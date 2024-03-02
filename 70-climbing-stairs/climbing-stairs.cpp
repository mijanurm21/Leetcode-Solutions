class Solution {
public:

int solve(int ind,  vector<int>& dp){
    if(ind == 1) return 1;
    if(ind == 2) return 2;
    if(dp[ind] != -1) return dp[ind];

    return dp[ind] = solve(ind-1, dp) + solve(ind-2, dp);


}
    
    int climbStairs(int n) {
        // memset(dp, -1, sizeof(dp));

        vector<int> dp(50, -1);
        return solve(n, dp);        
    }
};