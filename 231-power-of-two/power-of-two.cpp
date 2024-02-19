class Solution {
public:
    bool isPowerOfTwo(int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(n<=0) return false;
        // return ((n&n-1) == 0);

        return((n & n-1)==0); 
    }
};