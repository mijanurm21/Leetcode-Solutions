class Solution {
public:
    int solve(int i ,int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i<0 || j<0) return INT_MAX;
        if(i == 0 && j==0) return grid[i][j];
        if(dp[i][j] != 0) return dp[i][j];
        // int left = 0, up = 0;
        int up = solve(i-1,j, grid,dp);
        int left = solve(i, j-1, grid,dp);

        return dp[i][j] = grid[i][j] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int n=grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));

       return solve(n-1,m-1, grid,dp);
        
    }
};