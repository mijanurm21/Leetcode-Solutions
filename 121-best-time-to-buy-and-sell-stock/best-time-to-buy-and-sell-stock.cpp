class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        int ans = 0, diff = 0, prev = nums[0];

        for(int i= 1; i<n; i++){
            if(prev > nums[i]){
                prev = nums[i];
            }
            else{
                diff = nums[i]-prev;
                ans = max(ans, diff);
            }
        }

        return ans;
    }
};