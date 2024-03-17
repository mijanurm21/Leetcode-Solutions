class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& v) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < v[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= v[1]) {
            v[0] = min(v[0], intervals[i][0]);
            v[1] = max(v[1], intervals[i][1]);
            i++;
        }
        ans.push_back(v);

        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }

};
