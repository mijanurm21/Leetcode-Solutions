class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

       long long ans = 0;

        int i = 0, j = 0;

        while(i<n){
            if(nums[i] == 0){
                j = i;

                while(j<n && nums[j] == 0) j++;
                int len = j-i;

                ans +=  (1LL * len * (len + 1)) / 2;
                i = j;

            }
            else i++;

        }
        return ans;
    }
};