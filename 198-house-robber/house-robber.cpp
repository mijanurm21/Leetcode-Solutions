class Solution {
public:
    int rob(vector<int>& nums) {
        int nextnext = 0;
        int next = 0;
        int curr = 0;
        for(int i = nums.size()-1; i>=0; i--){
            int t = nums[i] + nextnext;
            int n = 0+next;

            curr = max(t, n);
            nextnext= next;
            next =  curr;
        }
        return curr;
    }
};