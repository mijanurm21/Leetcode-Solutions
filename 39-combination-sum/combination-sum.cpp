class Solution {
public:
    void solve(vector<int> &arr, int target, int ind,vector<int> &ds, vector<vector<int>> &ans ){
        if (ind == arr.size()) {
            if (target == 0) {
            ans.push_back(ds);
            }
            return;
      }
     
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        solve(arr, target - arr[ind], ind, ds, ans);
        ds.pop_back();
      }

      solve(arr, target , ind+1, ds, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(nums, target, 0, v, ans);

        return ans; 
    }
};