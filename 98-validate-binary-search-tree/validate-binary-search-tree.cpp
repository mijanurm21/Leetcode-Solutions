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
    void solve(TreeNode* root, vector<int>&ans){
        if(root == NULL) return ;

        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;

        solve(root, ans);

        if(is_sorted(ans.begin(), ans.end()) && adjacent_find(ans.begin(), ans.end()) == ans.end()) return true;
        else return false;
    }
};