class Solution {
public:

    int solve(vector<int>v){
        int count = 0;
        int ans =0;
        for(int num : v){
            if(num == 0){
                count = 0;
            }
            else{
                count++;
            }
            ans+= count;
        }
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for(int startRow = 0; startRow<m; startRow++){

            vector<int>v(n,1);
            for(int endRow = startRow; endRow <m; endRow++){


                for(int col = 0; col<n; col++){
                    v[col] = v[col] & mat[endRow][col];
                }

                ans += solve(v);

            }
        }
        return ans;
    }
};