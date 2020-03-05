// 225. Implement Stack using Queues (https://leetcode.com/problems/implement-stack-using-queues/)
// Author: Hritik Gupta

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();

        q.push(x);
        
        for(int i=0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q.size() == 0)
            return -1;
        int del = q.front();
        q.pop();
        return del;
    }
    
    /** Get the top element. */
    int top() {
        if(q.size() == 0)
            return -1;
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */