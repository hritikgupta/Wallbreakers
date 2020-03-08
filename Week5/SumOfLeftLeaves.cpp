// 404. Sum of Left Leaves (https://leetcode.com/problems/sum-of-left-leaves/)
// Author: Hritik Gupta

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool isLeaf(TreeNode *node){
        if(node->left == NULL && node->right == NULL)
            return true;
        return false;
    }
    
    void solve(TreeNode *root, int &ans){
        if(root == NULL)
            return;
        
        if(root->left && isLeaf(root->left))
            ans += root->left->val;
        solve(root->left, ans);
        solve(root->right, ans);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        solve(root, ans);
        
        return ans;
    }
};