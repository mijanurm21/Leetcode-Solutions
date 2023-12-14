class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1 ;
        int left = arr[l++], right = arr[r--] ;
        int ans = 0 ;
        while(l<=r) {
            if(left<=right) {
                while(arr[l]<left) {
                    ans += left-arr[l++] ;
                }
                left = arr[l++] ;
            }
            else {
                while(arr[r]<right) {
                    ans += right-arr[r--] ;
                }
                right = arr[r--] ;
            }
        }
        return ans ;
    }
};