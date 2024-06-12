class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int mid_inx;

        for(int i= 0; i<n; i++){       // selection sort
            mid_inx = i;
            for(int j = i+1; j<n; j++){
                if(nums[j] < nums[mid_inx])
                mid_inx = j;
            }
            if(mid_inx != i) swap(nums[mid_inx], nums[i]);
        }
    }
};