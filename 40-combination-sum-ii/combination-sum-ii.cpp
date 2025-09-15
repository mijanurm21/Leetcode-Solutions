class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>&ans, int i, vector<int>&temp, int sum){
        if(target == sum){            
            ans.push_back(temp);
            return ;
        }

        if(i>=nums.size()){
            if(sum == target){
                 ans.push_back(temp);
            }
            return;
        }

        for(int j = i; j<nums.size(); j++){
            if(j>i && nums[j] ==  nums[j-1]) continue;
            if(sum+nums[j] > target)  break;
            temp.push_back(nums[j]);
            solve(nums, target, ans, j+1, temp, sum+nums[j]);
            temp.pop_back();
        }        
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;

        solve(candidates, target, ans, 0, temp, 0);
       
        return ans;
    }
};