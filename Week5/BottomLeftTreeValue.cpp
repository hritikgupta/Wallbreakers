// 513. Find Bottom Left Tree Value (https://leetcode.com/problems/find-bottom-left-tree-value/)
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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> levels;
        while(q.size() > 1){
            TreeNode *temp = q.front();
            q.pop();
            
            if(temp == NULL){
                levels.clear();
                q.push(NULL);
            }
            else{
                levels.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        return levels[0];
    }
};