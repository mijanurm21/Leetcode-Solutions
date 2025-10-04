class Solution {
public:
    int n;

    int solve(string &s, int prev_val, int curr_ind, vector<vector<int>> &dp) {
        if (curr_ind >= n) return 0;
        if (dp[curr_ind][prev_val] != -1) return dp[curr_ind][prev_val];

        int flip = INT_MAX, nflip = INT_MAX;

        if (prev_val == 0) {
            if (s[curr_ind] == '0') {
                nflip = solve(s, 0, curr_ind + 1, dp);
                flip = 1 + solve(s, 1, curr_ind + 1, dp);
            } else {
                nflip = solve(s, 1, curr_ind + 1, dp);
                flip = 1 + solve(s, 0, curr_ind + 1, dp);
            }
        } else {
            if (s[curr_ind] == '1') {
                nflip = solve(s, 1, curr_ind + 1, dp);
            } else {
                flip = 1 + solve(s, 1, curr_ind + 1, dp);
            }
        }

        return dp[curr_ind][prev_val] = min(flip, nflip);
    }

    int minFlipsMonoIncr(string s) {
        n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(s, 0, 0, dp);
    }
};
