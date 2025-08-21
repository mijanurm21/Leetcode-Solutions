class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1) return 1;
         if(n == 0) return 0;


        int ans = 0;

        for(int num : st){
            if(st.find(num-1) == st.end()){
                int count = 1;
                int numc = num;
                while(st.find(numc+1)!= st.end()){
                    count++;
                    numc++;
                }
                ans = max(ans, count);
             
            }
        }
        return ans;

    }
};