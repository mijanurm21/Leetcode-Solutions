class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> temp;
        vector<string> ans(score.size());

        if (score.size() == 0)
            return ans; 

        if (score.size() == 1) {
            ans[0] = "Gold Medal"; 
            return ans;
        }

        if (score.size() == 2) {
            temp.push_back({score[0], 0});
            temp.push_back({score[1], 1});
            sort(temp.rbegin(), temp.rend());  

            ans[temp[0].second] = "Gold Medal";
            ans[temp[1].second] = "Silver Medal";

            return ans;
        }


        for(int i = 0; i<score.size(); i++){
            temp.push_back({score[i], i});
        }

        sort(temp.rbegin(), temp.rend());  // 10,9,8,4,3

         ans[temp[0].second] = "Gold Medal";
         ans[temp[1].second] = "Silver Medal";
         ans[temp[2].second] = "Bronze Medal";

        
        for(int i = 3; i<temp.size(); i++){
            auto it = temp[i];

           ans[temp[i].second] = to_string(i+1);
        }
        return ans;
    }
};