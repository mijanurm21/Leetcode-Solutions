
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        // priority_queue<pair<int , pair<int , int>>> pq;
                        // side      level val
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

                                // level side
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0,0}});

        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int level = q.front().second.first;
            int side = q.front().second.second;

            pq.push({side,{level, temp->val}});

            q.pop();

            if(temp->left){
                q.push({temp->left,{level+1, side-1 }});
            }
            if(temp->right){
                q.push({temp->right,{level+1, side+1}});
            }


        }

        while(!pq.empty()){
            vector<int> temp;
            int side = pq.top().first;
            while (!pq.empty() && pq.top().first == side) {
                int val = pq.top().second.second;
                pq.pop();
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};