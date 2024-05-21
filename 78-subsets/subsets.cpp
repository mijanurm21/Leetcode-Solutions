class Solution {
    void solve(int ind, int n, vector<vector<int>>&v, vector<int>nums, vector<int> t){

        if(ind>=n){
             v.push_back(t);
             return ;
        }
        t.push_back(nums[ind]);
        solve(ind+1, n, v, nums,t);
        t.pop_back();
        solve(ind+1, n, v, nums,t);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>v;
        int n = nums.size();
        vector<int> t;
        solve(0,n, v, nums,t);

        return v;
        
    }
};