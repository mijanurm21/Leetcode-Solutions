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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;

        long  ans = 0; 
        q.push({root, 0});

        while(!q.empty()){
            long  l = q.front().second;
            long  r = q.back().second;

            ans = max(ans, r-l+1);

            int n = q.size();
            while(n--){
                TreeNode* node = q.front().first;
                long ind = q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left, 2*ind+1});
                }
                if(node->right){
                    q.push({node->right, 2*ind+2});
                }
            }
        }
        return ans;
    }
};