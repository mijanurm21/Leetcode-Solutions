class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count+=4;
                        if(i+1 < m && grid[i+1][j] ==1) count--;
                        if(i-1 >=0  && grid[i-1][j] ==1) count--;
                        if(j+1 < n && grid[i][j+1] ==1) count--;
                        if(j-1 >=0 && grid[i][j-1] ==1) count--;
                    }
                }
        }
        return count;
    }
};