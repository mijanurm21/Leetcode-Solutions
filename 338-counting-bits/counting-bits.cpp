class Solution {
public:

    int popcount(int x) {
    int count = 0;
        while (x) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> v(n+1,0);

        for(int i = 0;i<=n; i++){
            v[i] = popcount(i);
        }
        return v;
    }
};