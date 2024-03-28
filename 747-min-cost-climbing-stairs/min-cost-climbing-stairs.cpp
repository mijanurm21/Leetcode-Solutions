class Solution {
public:
    int solve(vector<int> a, int i, vector<int>&dp){
        if(i<=1)   return a[i];
        if(dp[i]!=-1) return dp[i];
        int s1 =  a[i] + solve(a, i-1, dp);
        int s2 = a[i] + solve(a, i-2, dp);
        return dp[i] = min(s1, s2);
    }
        

    int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int> dp(n+2,-1);
        return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    }
};