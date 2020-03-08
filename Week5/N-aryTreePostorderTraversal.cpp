// 590. N-ary Tree Postorder Traversal (https://leetcode.com/problems/n-ary-tree-postorder-traversal/)
// Author: Hritik Gupta

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        
        if(root == NULL)
            return res;
        
        stack<Node *> s1;
        stack<int> s2;
        
        s1.push(root);
        
        while(!s1.empty()){
            Node *temp = s1.top();
            s1.pop();
            
            s2.push(temp->val);
            vector<Node *> childs = temp->children;
            for(int i=0; i<childs.size(); i++){
                s1.push(childs[i]);
            }
        }
        
        while(!s2.empty()){
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};