class Solution {
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
            return INT_MAX;
        }
        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];


        int down = solve(i + 1, j - 1, matrix,dp);
        int downp1 = solve(i + 1, j, matrix,dp);
        int downm1 = solve(i + 1, j + 1, matrix,dp);

        return dp[i][j] = matrix[i][j] + min(down, min(downp1, downm1));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int ans = INT_MAX;
        
        vector<vector<int>>dp(n, vector<int>(n,INT_MAX));

        for(int j = 0; j<n ;j++){
            ans = min(ans, solve(0,j,matrix,dp));
        }
        return ans;
    }
    
};
