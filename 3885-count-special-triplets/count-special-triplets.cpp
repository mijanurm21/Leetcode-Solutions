class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;
        unordered_map<int, vector<int>>mp;

        for(int i = 0;i <n; i++){
            mp[nums[i]].push_back(i);
        }

        long long count = 0;

        for(int j = 0; j<n; j++){
            int num = nums[j];
            if(mp.find(num*2) != mp.end()){
                auto &temp = mp[num*2];
                auto upper = upper_bound(temp.begin(), temp.end(), j);
                auto it = lower_bound(temp.begin(), temp.end(), j);


                long long before = it - temp.begin();  // Count of indices < j
                long long after = temp.end() - upper;


                // cout<<lessthan<<" "<<greaterthan<<endl;
                count = (count + (before * after) % MOD) % MOD;
            }
        }
        return (int)(count % MOD);
    }
};