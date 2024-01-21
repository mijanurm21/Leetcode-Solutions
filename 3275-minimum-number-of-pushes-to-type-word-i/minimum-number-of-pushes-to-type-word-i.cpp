class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, n = word.size(), r = 1;

        int t = n/8;
        int rem = n%8;

        while(t--){
            ans+=8*r;
            r++;
        }
        ans+=rem*r;
        return ans;
    }
};