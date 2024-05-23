class Solution {
public:
    bool check(int x, int k, vector<int> &nums){
        for(auto &i: nums){
            if(abs(x - i) == k){
                return false;
            }
        }
        return true;
    }

    int solve(int ind, int n, vector<int>&nums, int k, vector<int>&ans){
        if(ind>=n) return ans.size() > 0 ? 1 : 0;

        int ntake = solve(ind+1, n, nums, k, ans);
        int take = 0;

        if(check(nums[ind], k, ans)){
            ans.push_back(nums[ind]);
            take = solve(ind+1, n, nums, k, ans);
            ans.pop_back();
        }
        return take + ntake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> ans;

        return solve(0, nums.size(), nums, k, ans);
    }
};