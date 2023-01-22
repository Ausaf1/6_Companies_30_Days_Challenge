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
    
   pair<int,int> dfs(TreeNode* root){
        if(!root)
            return {0,0};  
        auto[l1,r1] = dfs(root->left);
        auto[l2,r2] = dfs(root->right);
        int withRoot = root->val + r1 + r2;
        int withoutRoot = max(l1,r1) + max(l2,r2);
        return {withRoot,withoutRoot};
    }
    
    int rob(TreeNode* root) {
       auto [rob,nrob] = dfs(root);
        return max(rob,nrob);
    }
};