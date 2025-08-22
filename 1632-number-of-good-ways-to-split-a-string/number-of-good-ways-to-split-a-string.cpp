class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;


        for(char ch: s){
            mp1[ch]++;
        }
        int count = 0;

        for(int i = 0;i<n; i++){
            mp2[s[i]]++;
            mp1[s[i]]--;
            if(mp1[s[i]] == 0) mp1.erase(s[i]);
            if(mp1.size() == mp2.size()) count++;
        }

        return count;
    }
};