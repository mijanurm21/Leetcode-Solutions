class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // return 0;
        int n = nums.size();
        int l = 0, h = n-1;
        if(nums.size() == 1) return 0;

        while(l<h){
            int mid = (l+h)/2;

            // if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
             if(nums[mid] < nums[mid+1]) l = mid+1;
            else h = mid;
        }
        return l;
    }
};