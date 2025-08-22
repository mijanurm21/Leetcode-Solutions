class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;

        for(int i = 0;i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int count = 0;
        for(int i = 0; i<words.size(); i++){
            string word = words[i];

            int prev = -1;
            bool flag = true;

            for(auto ch : word){
                if(mp.find(ch) == mp.end()){
                    flag = false;
                    break;


                }
                auto it = upper_bound(mp[ch].begin(), mp[ch].end(), prev);

                if(it == mp[ch].end()){
                    flag = false;
                     continue;
                }
                
                    prev = *it;
               
            }
            if(flag) count++;
        }
        return count;
    }
};