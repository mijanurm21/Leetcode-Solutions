class Solution {
public:
    string mergeAlternately(string s, string t) {
        string ans;
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        while(i<n || j<m){
            if(i<n) ans.push_back(s[i++]);
            if(j<m) ans.push_back(t[j++]);
        }
        return ans;

      
    }
};