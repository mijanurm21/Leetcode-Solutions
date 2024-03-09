class Solution {
public:
    int solve(string s, int ind, int n, vector<int> &dp){
        if(ind == n) return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind] != -1)  return dp[ind];

        int count = solve(s, ind+1, n, dp);
        if(ind < n-1 && s.substr(ind, 2) < "27") {
            count+= solve(s, ind+2, n, dp);
        } 
        return dp[ind] = count;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(103, -1) ;
        // return solve(s, 0, n, dp);
        return solve(s, 0, n, dp);
    }
};