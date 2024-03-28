class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> mp;

        if(nums.size() == 1) return 1;

        while(i<n && j<n){
            mp[nums[j]]++;
            
            while (mp[nums[j]] > k){
                
                mp[nums[i]]--;
                i++;
            }
                
            ans = max(ans, j - i + 1);
        
            j++;
            
        }
        return ans;
    }
};