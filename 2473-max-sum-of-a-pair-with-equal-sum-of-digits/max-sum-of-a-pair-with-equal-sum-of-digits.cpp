class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
                    //sum  num
        unordered_map<int, int> mp;
        int ans = -1;

        for(int i= 0; i<n; i++){
            int num = nums[i];
            int sum = 0;
            while(num>0){                
                sum += (num%10);
                num = num/10;
            }

            if(mp.find(sum) != mp.end()){  // mil jata h
                ans = max(ans, mp[sum]+nums[i]);
                if(nums[i] > mp[sum]) mp[sum] = nums[i];
            }
            else{
                mp[sum] = nums[i];
            }
        }

        
        return ans;
    }
};