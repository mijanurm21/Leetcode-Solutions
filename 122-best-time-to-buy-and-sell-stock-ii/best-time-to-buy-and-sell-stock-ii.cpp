class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int tot = 0, diff = 0, prev = nums[0];


        for(int i  = 1; i<n; i++){
            if(prev < nums[i]){
                tot+=nums[i]-prev;
            }
            prev = nums[i];
        }

        return tot;
    }
};