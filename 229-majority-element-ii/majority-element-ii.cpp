class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int k = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        // vector<int> hash(100000000,0);
        unordered_map<int, int> hash;

        for(int i = 0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        for(auto hash : hash) {
            int element = hash.first;
            int count = hash.second;
            
           
            if(count > n/3) {
                ans.push_back(element);
            }
        }
        return ans;
        }
    
};