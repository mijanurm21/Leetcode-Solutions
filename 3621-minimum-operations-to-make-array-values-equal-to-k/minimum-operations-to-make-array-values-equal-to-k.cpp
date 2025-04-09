class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i = 0;i<n; i++){
            if(nums[i] < k) return -1;
            else {
                if(nums[i] == k) continue;
                mp[nums[i]]++;
            }
        }
        return mp.size();
    }
};