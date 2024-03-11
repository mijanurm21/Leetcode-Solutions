class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;

        for(auto c : order){
            mp[c] = 0;
        }

        for(auto c : s){
            if (mp.find(c) != mp.end()) {
                mp[c]++;
            }
        }

        string ans;

        for(auto c : order){
            ans.append(mp[c],c);
        }

        for(char c: s){
           if( mp.find(c) == mp.end()) ans.push_back(c);
        }

return ans;

    }
};