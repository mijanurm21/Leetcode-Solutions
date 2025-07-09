class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        vector<string>s = strs;

        for(int i = 0;i<s.size(); i++){
            sort(s[i].begin(), s[i].end());
        }

     
        unordered_map<string, vector<int>> mp;

        for(int i = 0;i<s.size(); i++){
            mp[s[i]].push_back(i);          
        }

   

        for(auto it : mp){
            vector<string> temp;
          
            for (auto val : it.second) {
               temp.push_back(strs[val]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};