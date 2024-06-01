class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int sum = 0;

        for(int i = 1; i<n; i++){
            sum += abs((s[i]-'0') - (s[i-1] - '0'));
        }
        return sum;
    }
};