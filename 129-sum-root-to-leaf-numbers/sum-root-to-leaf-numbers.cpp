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
    void solve(TreeNode* root, vector<string>&v, string s){
        // if(!root) return ;
        if(root->left == NULL && root->right == NULL) {
            s+=to_string(root->val);
            v.push_back(s);
            return ;
        }

        // s.push_back(root->val);
        s+=to_string(root->val);
        if(root->left)solve(root->left, v, s);
        if(root->right)solve(root->right, v, s);

        s.pop_back();


    }
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        string s ;

        solve(root, v,s);

        int sum = 0;

        for(int i = 0; i<v.size(); i++){
            // cout<<v[i]<<" ";
            sum+=stoi(v[i]);
        }
        return sum;
    }
};