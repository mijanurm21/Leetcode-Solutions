class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> m;

        for(auto it : edges){
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
            
        }

        vector<bool> visited(n+1, false);

        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
           int temp = q.front();
           q.pop();

           auto it =  m[temp];  // it m vector h
           
           for(int i = 0;i<it.size(); i++){
                int node = it[i];
                if(visited[node] == false){
                    visited[node] = true;
                    q.push(node);
                }
                if(visited[destination]) return visited[destination];
           }


        }
        return visited[destination];
    }
};