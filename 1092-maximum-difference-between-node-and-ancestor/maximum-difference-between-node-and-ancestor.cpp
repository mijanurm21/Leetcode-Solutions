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
    int solve(TreeNode* root, int mini, int maxi){
        if(!root) return maxi - mini ;

        mini = min(root->val, mini);
        maxi = max(root->val, maxi);

        int left =  solve(root->left, mini, maxi);
        int right =  solve(root->right, mini, maxi);

        return max(left, right);

    }
    int maxAncestorDiff(TreeNode* root) {
       if(!root) return 0;
        int ans = solve(root, root->val, root->val);
        
        return ans;
        



    }
};