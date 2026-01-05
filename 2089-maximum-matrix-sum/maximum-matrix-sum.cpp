class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        long long total_sum = 0;
        int mini = INT_MAX;
        int neg_count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] < 0){
                    neg_count++;
                }

                int val = abs(mat[i][j]);
                total_sum += val;
                mini = min(mini, val);
            }
        }

        if(neg_count % 2 == 0)
            return total_sum;
        else
            return total_sum - 2LL * mini;
    }
};
