class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();


        int pre = 1;
        vector<int> res(n,1);

        for(int i = 0;i<n; i++){
            res[i] = pre;
            pre*=nums[i];
        }

        int suff = 1;

        for(int i = n-1; i>=0; i--){
            res[i] *= suff;
            suff *= nums[i];
        }

        return res;
    }
};