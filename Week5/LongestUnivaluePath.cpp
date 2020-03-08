// 687. Longest Univalue Path (https://leetcode.com/problems/longest-univalue-path/)
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
        
        int left_longest_path = solve(root->left, ans);
        int right_longest_path = solve(root->right, ans);
        int left = 0;
        int right = 0;
        if(root->left && root->val == root->left->val)
            left = left_longest_path + 1;
        if(root->right && root->val  == root->right->val)
            right = right_longest_path + 1;
        
        ans = max(ans, left+right);
        return max(left, right);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};