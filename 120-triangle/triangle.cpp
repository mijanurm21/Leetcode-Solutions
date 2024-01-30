class Solution {
    int solve(int i, int j, vector<vector<int>>& nums, vector<vector<int>> &dp){
        if(i == nums.size()-1) return nums[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = nums[i][j] + solve(i+1, j, nums,dp);
        int downp1 = nums[i][j] + solve(i+1, j+1, nums,dp);

        return dp[i][j] = min(down, downp1);
    }
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n  = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, 0, nums, dp);
    }
};