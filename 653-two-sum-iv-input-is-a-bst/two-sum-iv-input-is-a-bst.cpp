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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int val = temp->val;

            if(mp.find(k-val) != mp.end()){
                return true;
            }

            mp[val]++;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);


        }
        return false;
    }
};