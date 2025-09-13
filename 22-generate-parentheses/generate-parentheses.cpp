class Solution {
public:
    void solve(string s, int o, int c, vector<string>& ans){
        if(o == 0 && c == 0) {
            ans.push_back(s);
            return;
        }
        
        if(o>0){
            solve(s+ '(', o-1, c, ans);
        }
        if(c>o)
        solve(s+ ')', o, c-1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, n , ans);

        return ans;
    }
};