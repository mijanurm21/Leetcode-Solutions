class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        int sum = nums[0], maxi = 0;

        while(j<n){
            if(nums[j] > nums[j-1])
             sum += nums[j];
             
            else{
                maxi= max(maxi, sum);
                i = j;
                sum=nums[i];
                // j = i+1;
            }
            j++;  
            // cout<<sum<<endl;          
        }
        maxi = max(sum , maxi);
        return maxi;


    }
};