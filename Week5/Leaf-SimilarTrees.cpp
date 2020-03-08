// 872. Leaf-Similar Trees (https://leetcode.com/problems/leaf-similar-trees/)
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
    
    void getLeaves(TreeNode *root, vector<int> &leaves){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
            leaves.push_back(root->val);
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return true;
        
        vector<int> a;
        getLeaves(root1, a);
        vector<int> b;
        getLeaves(root2, b);
        return a==b;
    }
};