class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> v(nums.size() , 0);
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1) v[i]++;
            else v[i]--;
           
        }

        int ans = 0;

        if(nums.size() == 2 && v[0] == v[1]) return 0;
        
        else if(nums.size() == 2 && v[0] != v[1]) return 2;

        unordered_map<int, int> mp;
        int prefixSum = 0;
        mp[0] = -1; 

        for (int i = 0; i < v.size(); i++) {
            prefixSum += v[i];

            if (mp.find(prefixSum - 0) != mp.end()) {
                int x = i - mp[prefixSum];
                ans = max(ans, x);
            } else {
                mp[prefixSum] = i;
            }
        }
        return ans;
    }
};