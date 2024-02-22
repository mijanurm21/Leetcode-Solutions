class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // isme logic ye h ki jb outdegree ho rha h to count -- kr rhe h or jb outdegree ho rha h tb count-- kr rhe h kyu ki agr koi town judge hoga to usko kisi pe trust nhi h ... to indegree usme n-1 hoga but outdegree 0 smja??
        
        vector<int> temp(n+1,0);
        for(auto x : trust){                

            temp[x[0]]--;
            temp[x[1]]++;
        }
        for(int i = 1; i<=n ;i++){
            int x = temp[i];
            if(x == n-1) return i;
        }
        return -1;
    }
};