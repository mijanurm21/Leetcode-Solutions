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

    void solve(TreeNode* root, int depth, int val, int ind){
        if(root == NULL) return ;

        if(ind == depth - 1){
            TreeNode *temp1 = root->left;
            TreeNode *temp2 = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = temp1;
            
            root->right->right = temp2;
        }
         solve(root->left, depth, val, ind+1);
        solve(root->right, depth, val, ind+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }

        solve(root, depth, val,1);
        // solve(root->right, depth, val,0);
        return root;
    }
};