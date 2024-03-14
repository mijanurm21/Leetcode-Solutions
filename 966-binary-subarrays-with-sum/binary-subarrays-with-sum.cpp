class Solution {
public:
    
   
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int k = goal;
        int count = 0;
        unordered_map<int,int> presum;
        int sum = 0;

        for(int i = 0; i<n; i++){
            sum = sum + nums[i];
            if(sum == k) count++;

            if(presum.find(sum-k) != presum.end())
            count+=presum[sum-k];
            presum[sum]++;
        }
        return count;
    }
};