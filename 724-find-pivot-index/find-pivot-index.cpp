class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i = 0; i<n; i++){
           tot_sum -= nums[i];
           if(sum == tot_sum) return i;
           sum+=nums[i];

        }
        return -1;
    }
};