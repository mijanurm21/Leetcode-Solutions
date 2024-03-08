class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mxi = *max_element(nums.begin(), nums.end());
        vector<int> hash(mxi+1,0);
        // if(nums.size() == 1) return 1;

        for(int i = 0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        int mx= *max_element(hash.begin(), hash.end());
        int sum = 0;

        for(int i = 0; i<hash.size(); i++){
            if(hash[i] == mx) sum+=hash[i];
        }
        return sum;
    }
};