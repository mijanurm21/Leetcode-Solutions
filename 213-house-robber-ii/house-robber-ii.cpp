class Solution {
    int solve(int n, vector<int> nums, vector<int>&dp){
        if(n == 0) return nums[0];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = nums[n] + solve(n-2, nums, dp);
        int npick = solve(n-1, nums, dp);
        return dp[n] =  max(pick, npick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1, temp2;
        vector<int> dp(n+1, -1);

        for(int i = 0;i<n; i++){
            if(i !=0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        int result1 = solve(temp1.size()-1, temp1, dp); 
        fill(dp.begin(), dp.end(),-1);
        int result2 =  solve(temp2.size()-1, temp2, dp);
        return max(result1, result2);
    }
};