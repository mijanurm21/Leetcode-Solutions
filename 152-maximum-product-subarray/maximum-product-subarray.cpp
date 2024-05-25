class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mul = 1;

        int maxi = INT_MIN;

        for(int i = 0; i<n;i++){
            mul*=nums[i];

            maxi = max(maxi, mul);

            if(mul == 0 ) mul = 1;
        }

        mul = 1;

        for(int i=nums.size()-1;i>=0;i--)
        {
          mul*=nums[i];

          maxi=max(mul,maxi);
          if(mul==0)
           mul=1;
        }
        return maxi;
    }
};