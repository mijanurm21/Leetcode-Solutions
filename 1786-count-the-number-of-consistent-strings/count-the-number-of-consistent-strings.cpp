class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();
        unordered_map<char , int> mp ,mp2;

        for(auto it : allowed){
            mp[it]++;
        }
        int count = 0;

        for(int i = 0; i<n; i++){
            bool flag = true;
            for(auto it : words[i]){
                if(mp.find(it) == mp.end()) {
                    flag = false;
                    break;
                }                
            }
            if(flag) count++;
        }
        return count;
    }
};