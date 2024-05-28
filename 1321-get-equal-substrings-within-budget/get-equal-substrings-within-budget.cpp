class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int n = s.size();
        vector<int> nums(n);

        for(int i = 0; i<n; i++){
            nums[i] = abs(s[i] - t[i]);
        }

        // for(int i = 0; i<n; i++){
        //     cout<<diff[i]<<" ";


        // }
        // cout<<endl;

        unordered_map<int, int> mp;
        int ans = 0;

        int sum = 0;

        int j = 0;
        
// subarray with sum k 
        for(int i= 0 ; i<n; i++){
            sum+=nums[i];

            while(sum > maxCost) {
                sum -= nums[j];
                j++;
            }

            
            ans = max(ans, i - j + 1);

        }

        // return 0;
        return ans;
    }
};