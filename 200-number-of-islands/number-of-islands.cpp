class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

      

        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        vector<vector<bool>>visited(n, vector<bool>(m,false));
        int count = 0;

        for(int i = 0;i <n; i++){
            for(int j = 0; j<m; j++){
               if(grid[i][j] == '1' && !visited[i][j]){
                count++;
                queue<pair<int, int>> q;
                q.push({i,j});
                visited[i][j] = true;

                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    
                    q.pop();

                    for(int k  = 0; k<4; k++){
                        int nrow = row + dr[k];
                        int ncol = col + dc[k];

                        if(nrow >= 0 && nrow <n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                            q.push({nrow, ncol});
                            visited[nrow][ncol] =  true;
                        }
                    }

                }

               }
            }
        }
        return count;       

        
    }
};