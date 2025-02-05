class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char, int> mp;

        int i = 0;
        int count = 0;

        for(auto it: s1){
            mp[it]++;
        }

        if(s1.size() != s2.size()) return false;

        while(i<s1.size()){
            if(s1[i] != s2[i]) count++;

            if(mp.find(s2[i]) != mp.end()){
                mp[s2[i]]--;
                if(mp[s2[i]] == 0)  mp.erase(s2[i]);
            } 
            i++;
        }

        if((count == 2 || count == 0) && mp.empty()) return true;
        return false;

    }
};