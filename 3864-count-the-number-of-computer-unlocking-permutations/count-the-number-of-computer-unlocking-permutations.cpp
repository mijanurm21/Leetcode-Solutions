#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long fact(int n) {
        if (n == 0 || n == 1)
            return 1;

        return (n * fact(n - 1) % MOD) % MOD;
    }

    int countPermutations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int mini = *min_element(nums.begin(), nums.end());

       
        if (mp[nums[0]] > 1 || nums[0] != mini)
            return 0;

       
        return (int)fact(n - 1);
    }
};
