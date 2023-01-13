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
    int cnt=0;
    pair<int,int> printPreorder(TreeNode* root)
    {
        int avg,node;
        if (root == NULL){
            return {0,0};
        }
        pair<int,int> left=printPreorder(root->left);
        pair<int,int> right=printPreorder(root->right);
        avg=left.first+right.first+root->val;
        node=left.second+right.second+1;
        if(avg/node==root->val) cnt++;
        return {avg,node};
    }
    
    
    
    int averageOfSubtree(TreeNode* root) {
        printPreorder(root);
        return cnt;
    }
};