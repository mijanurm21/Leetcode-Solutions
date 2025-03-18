class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int mask = 0, startInd = 0, ans = 0;
        
        for(int i = 0;i<n; i++){
            
            while((mask & nums[i]) != 0){
                mask^=nums[startInd];
                startInd++;
            }

            mask = mask ^ nums[i];

            ans = max(ans, i-startInd+1);
        }
        

        return ans;
    }
};