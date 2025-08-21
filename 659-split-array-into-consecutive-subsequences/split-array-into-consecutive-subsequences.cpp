class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> vmp;

        int n = nums.size();

        for(int i = 0;i<n; i++){
            mp[nums[i]]++;
        }

        for(int i = 0;i<n; i++){
            if(mp[nums[i]] <= 0) continue;

            if(vmp[nums[i]] > 0){
                mp[nums[i]]--;
                vmp[nums[i]]--;
                vmp[nums[i] + 1]++;
            }
            else if(mp[nums[i]] > 0 && mp[nums[i]+1]>0 && mp[nums[i]+2] > 0){
                mp[nums[i]]--;
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;

                vmp[nums[i]+3]++;
                
            }
            else return false;
        }
        return true;

    }
};