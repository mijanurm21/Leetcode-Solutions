class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, vector<int>> mp2;
        
        for(auto it: buildings){
            int x = it[0];
            int y = it[1];

            mp[x].push_back(y);
            mp2[y].push_back(x);
        }
        int count = 0;

        for (auto& [x, vec] : mp) 
            sort(vec.begin(), vec.end());
        for (auto& [y, vec] : mp2)
            sort(vec.begin(), vec.end());

        for(auto it: buildings){
            int x = it[0];
            int y = it[1];

            auto& tempx = mp[x];
            auto& tempy = mp2[y];

            int size_x = tempx.size();
            int size_y = tempy.size();


            auto itx = lower_bound(tempx.begin(), tempx.end(), y);
            auto ity = lower_bound(tempy.begin(), tempy.end(), x);

            int lower_in_x = itx - tempx.begin();
            int lower_in_y = ity - tempy.begin();

            if((lower_in_x > 0 && lower_in_x < size_x -1) && (lower_in_y > 0 && lower_in_y < size_y -1)){
                count++;
            }



        }
        return count;
    }
};