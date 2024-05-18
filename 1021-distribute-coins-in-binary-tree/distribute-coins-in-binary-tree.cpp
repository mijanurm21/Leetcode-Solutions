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

    int solve(TreeNode* root, int& moves){
        if(root == NULL) return 0;

        int right = solve(root->right, moves);
        int left = solve(root->left, moves);

        moves += abs(right) +  abs(left);

        return (right + left + root->val) - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
         solve(root, moves);
        return moves;

    }
};