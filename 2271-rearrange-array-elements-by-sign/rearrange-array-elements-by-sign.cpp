class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int pos = 0, neg = 1;

        for(auto i : nums){
            if(i > 0){
                ans[pos] = i;
                pos+=2;
            }
            if(i<0){
                ans[neg] = i;
                neg+=2;
            }
        }
        return ans;

    }
};