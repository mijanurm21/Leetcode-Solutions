class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long s = 1;
        int count = 0;
        while(i<n){
            s*=nums[j];
            if(s<k) {
                count++;
                j++;
            }
            if (j == n || s >= k) {
                i++;
                j = i;
                s = 1;
    }
           
        }
        return count ;
    }
};