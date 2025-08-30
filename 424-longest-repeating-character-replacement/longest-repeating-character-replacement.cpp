class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int>v(26,0);
        int maxfreq = 0, ans = 0;

        int i = 0, j = 0;

        while(j<n){
            v[s[j] - 'A']++;
            
            maxfreq = max(maxfreq, v[s[j]-'A']);

            while((j-i+1) - maxfreq > k){
                v[s[i] - 'A']--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;

        }
        return ans;
    }
};