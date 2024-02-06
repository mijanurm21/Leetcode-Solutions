class Solution {
public:
    bool solve(string copy, string word, int n){
        for(int i= 0; i<n; i++){
            if(copy[i] != '#' && copy[i] != word[i]) return false;
        }
        return true;
    }
    int minimumTimeToInitialState(string word, int k) {
        string copy = word, hash = "";
        int n = word.size();
        int ans = 0;
        for(int i = 0; i<k; i++) hash+="#";

        while(1){
            copy = copy.substr(k)+hash;
            ans++;
            if(solve(copy, word, n)) return ans;

        }

return 0;
    }
};