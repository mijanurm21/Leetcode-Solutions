/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int>result ;
            if (root == nullptr) return result; 

        q.push(root);

        while(!q.empty()){
            int n = q.size();
           vector<int> temp;

          while(n--){
            TreeNode *node = q.front();
            q.pop();
            int val  = node->val;
            temp.push_back(val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
           } 
           ans.push_back(temp);
        }
        
        for(int i = 0; i<ans.size(); i++){
            int n = ans[i].size();
            result.push_back(ans[i][n-1]);
        }
        return result;
    }
};