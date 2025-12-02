class Solution {
public:
     bool solve(const vector<int>& nums, long long time, int comp) {
        long long sum = 0;
        int n = nums.size();
        int count = 0;
        for (int x : nums) {
          sum += min(1LL * x, time);

           
        }
        return sum >= 1LL * comp * time;

    }
    long long maxRunTime(int n, vector<int>& nums) {
        long long l = 0, h = accumulate(nums.begin(),nums.end(), 0LL);
        long long ans = 0;
        while(l<=h){
            long long mid = (l+h)/2;

            if(solve(nums, mid,n)){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }

        }

        return ans;
    }
};