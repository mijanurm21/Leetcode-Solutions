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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i<preorder.size(); i++){
            int val = preorder[i];
            TreeNode* prev = root;
            while(true){
                if(val > prev->val) {
                    if(prev->right == NULL) {
                        prev->right = new TreeNode(val);
                        break;
                    }
                    else prev = prev->right;
                }
                else{
                    if(prev->left == NULL) {
                        prev->left = new TreeNode(val);
                        break;
                    }
                    else prev = prev->left;
                }
            }

        }
        return root;
    }
};