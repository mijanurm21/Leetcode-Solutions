class Solution {
public:
// ----------------------------------------------------------------------
    // int solve(int n,vector<int>nums){
    //     if(n == 0) return nums[n];
    //     if(n<0) return 0;
    //     int pick = nums[n] + solve(n-2, nums);   // RECURSION
    //     int npick = 0 + solve(n-1, nums);

    //     return max(pick ,npick);
    // }
    // ----------------------------------------------------------------------

    // int solve(int n, vector<int>nums, vector<int>&dp){
    //     if(n == 0) return nums[n];
    //     if(n<0) return 0;
    //     if(dp[n] != -1)  return dp[n];

    //     int pick = nums[n] + solve(n-2 ,nums, dp );   // MEMOIZATION 
    //                                                 // BOTTOM UP 
    //     int npick = 0+ solve(n-1, nums, dp);
    //     return dp[n] = max(pick , npick);
    // }
    // --------------------------------------------------

    // void solve(vector<int>nums, vector<int>&dp){
    //     dp[0] = nums[0];
    //     for(int i = 1; i<nums.size(); i++){
    //         int pick = nums[i];
    //         if(i>1) pick += dp[i-2];
    //         int npick = 0 + dp[i-1];

    //         dp[i] =  max(pick , npick);
    //     }
    // }
    // -------------------------------------------------------
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        //  solve( nums, dp);
        //  return dp[n-1];



        int prev2 = 0, prev = nums[0];

        for(int i = 1; i<n; i++){
            int pick = nums[i];
            if(i>1) pick+=prev2;
            int npick = 0 + prev;

            int curi = max(pick , npick);
            prev2 = prev;
            prev = curi;

        }
        return prev;
    }
};