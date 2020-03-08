// 543. Diameter of Binary Tree (https://leetcode.com/problems/diameter-of-binary-tree/)
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
    
    int solve(TreeNode *root, int &ans){
        if(root == NULL)
            return 0;
        
        int left_longest = solve(root->left, ans);
        int right_longest = solve(root->right, ans);
        
        int left = 0;
        int right = 0;
        if(root->left)
            left = left_longest + 1;
        if(root->right)
            right = right_longest + 1;
        
        ans = max(ans, left + right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        solve(root, ans);
        
        return ans;
    }
};