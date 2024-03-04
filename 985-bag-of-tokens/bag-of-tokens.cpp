class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int l = 0, r = tokens.size()-1, score = 0;
        int maxi = 0;

        while(l <= r){
            if(power >= tokens[l]){
                power-= tokens[l];
                score++;
                l++;
                maxi = max(score, maxi);

            }
            else if(score>0){
                power+=tokens[r];
                r--;
                score--;
            }
            else break;
        }
        return maxi;
    }
};