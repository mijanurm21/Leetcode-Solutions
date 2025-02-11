class Solution {
public:
    bool solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(i>=j) return true;
        if(dp[i][j] != false) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] =  solve(i+1, j-1, s, dp);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        string ans;
        int maxi = 0;

        for(int i = 0;i<n; i++){
            for(int j = i; j<n; j++){
                if(solve(i,j,s,dp)){
                    int temp = j-i+1;
                    if(temp>maxi){
                        maxi= temp;
                        ans = s.substr(i,temp);
                    }
                }
            }
        }
        return ans;
    }
};