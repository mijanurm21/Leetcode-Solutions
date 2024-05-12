class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> fin(n-2,vector<int>(n-2));

        for(int i=0;i<n-2;i++){
            for(int j=0; j<n-2;j++){
                fin[i][j]=funn(grid,i,j);
            }
        }
        return fin;
    }

    int funn(vector<vector<int>> &a,int i,int j){

        int maxx = INT_MIN;
        for(int x = i; x<i+3; x++){
            for (int y = j; y<j+3; y++){
                maxx = max(a[x][y], maxx);
            }
        }
        return maxx;
    }
};