class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        // if(n == 1) return {nums[0]};
        vector<int> ans;
       

        int i = 0, j = 0;

        while(j<n){ 

            pq.push({nums[j], j}); 

            if (j-i+1>k) {
                i++;
            }          
           
            if(j-i+1 == k){
                while(!pq.empty() && pq.top().second < i){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
               
            }
            j++;
        }
        // ans.push_back(pq.top().first);
        return ans;
    }
};