class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int best = values[0] + 0;
        int ans = INT_MIN;

        for(int i = 1; i<n; i++){
            int score = best + (values[i] - i);
            ans = max(ans, score);
            best = max(best, values[i] + i);
        }
        return ans;
    }
};