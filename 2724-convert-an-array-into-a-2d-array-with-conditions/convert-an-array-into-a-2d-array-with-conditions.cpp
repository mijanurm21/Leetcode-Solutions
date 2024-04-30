class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;

        int n = nums.size();

        for(int i= 0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> ans;

        while(!mp.empty()){
            vector<int> v;

            vector<int> del;

            for (auto &it : mp) {
                if (it.second > 0) {
                    v.push_back(it.first);
                    it.second--;
                    if (it.second == 0) del.push_back(it.first);
                }
            }


            for(auto it: del){
                mp.erase(it);
            }

            ans.push_back(v);

        }
        return ans;
    }
};