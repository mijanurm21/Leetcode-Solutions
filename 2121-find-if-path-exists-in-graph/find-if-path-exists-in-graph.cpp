class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(edges.size() == 0) return true;
        unordered_map<int, vector<int>> m;
        for(auto x: edges){
            vector<int> temp = x;

            int u = temp[0];
            int v = temp[1];

            m[u].push_back(v);
            m[v].push_back(u);
        }        

        vector<bool>vis(n+1,false);

        queue<int>q;
        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            vector<int> v = m[temp];
            for(int i = 0; i<v.size(); i++){
                int vertex = v[i];
                if(vis[vertex] == false){
                    q.push(vertex);
                    vis[vertex] = true;
                }
            }
            if(vis[destination])
            return vis[destination];
        }

        return vis[destination];
    }
};