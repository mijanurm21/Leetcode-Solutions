class Solution {
public:
    bool check(vector<vector<int>>& queries, vector<int> nums, int mid) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0); 

        for (int i = 0; i <= mid; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];

            prefix[left] += val;
            if (right + 1 < n) prefix[right + 1] -= val;
        }

        int currentReduction = 0;
        for (int i = 0; i < n; i++) {
            currentReduction += prefix[i];
            nums[i] = max(0, nums[i] - currentReduction); 
        }

       return accumulate(nums.begin(), nums.end(), 0LL) == 0;
    }

    int minZeroArray(vector<int> nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
     
       if (accumulate(nums.begin(), nums.end(), 0LL) == 0) return 0; 

        
        int maxElement = *max_element(nums.begin(), nums.end());
        int l = 0, h = n-1;
        int ans = -1;

        while(l<=h){
            int mid = (l+h)/2;
            
            if (check(queries, nums, mid)) {  
                ans = mid + 1;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;

    }
};