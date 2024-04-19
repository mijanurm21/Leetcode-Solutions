class Solution {
public:
    bool solve(int ind, vector<int>& nums, int currentSum, int target, vector<vector<int>>& dp) {
        if (currentSum == target) return true;
        if (ind == nums.size() || currentSum > target) return false;

        if (dp[ind][currentSum] != -1) return dp[ind][currentSum];

        bool pick = solve(ind + 1, nums, currentSum + nums[ind], target, dp);
        bool notPick = solve(ind + 1, nums, currentSum, target, dp);

        return dp[ind][currentSum] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) return false; // If totalSum is odd, it cannot be partitioned into two equal parts

        int target = totalSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(0, nums, 0, target, dp);
    }
};
