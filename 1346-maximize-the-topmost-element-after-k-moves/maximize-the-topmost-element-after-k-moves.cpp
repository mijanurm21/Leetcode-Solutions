class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size() == 1 && k%2) return -1;
        // priority_queue<int> q;

        int i = 0;
        // k--;
        int mx = -1;
        while(i<k-1  && i<nums.size()){
           mx = max(mx, nums[i]);
           i++;
        }

        if(k<nums.size()){
            mx = max(mx, nums[k]);
        }

        return mx;




    }
};