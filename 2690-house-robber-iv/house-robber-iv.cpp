class Solution {
public:
    bool check(vector<int>nums, int mid, int k){
        int count = 0;
        int i = 0;

        while(i<nums.size()){
            if(nums[i] <= mid) {
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());

        int ans = 0;
        while(l<=h){
            int mid= (l+h)/2;

            if(check(nums, mid, k)){
                ans = mid;
                h =  mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans; 
    }
};