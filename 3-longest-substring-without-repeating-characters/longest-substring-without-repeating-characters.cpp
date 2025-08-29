class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<int, int> mp;
     

        int i = 0, j = 0;
        int ans = 0;

        while(j<n){
          
            mp[s[j]]++;          
    
            
                
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }

                ans = max(ans, int(mp.size()));

         
            j++;
        }
        return ans;
    }
};