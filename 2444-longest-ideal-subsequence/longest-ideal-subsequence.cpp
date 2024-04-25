class Solution {
public:// this is mine
    int solve(string &s, int k, int ind, int t, vector<vector<int>>&dp){
        if(ind>=s.size()) return 0;
        if(dp[ind][t]!= -1) return dp[ind][t];

        int pick = 0;
        if(t==0 || abs(s[ind]-t)<=k)
        pick = 1+solve(s,k,ind+1, s[ind], dp);
        int npick = solve(s,k,ind+1, t, dp);

        return dp[ind][t] = max(pick , npick);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp (s.size()+1,vector<int>(150,-1));
        return solve(s,k,0 ,0, dp);        
    }
};