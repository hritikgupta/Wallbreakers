// 232. Implement Queue using Stacks (https://leetcode.com/problems/implement-queue-using-stacks/)
// Author: Hritik Gupta

class MyQueue {
public:
    /** Initialize your data structure here. */
    
    stack<int> s;
    stack<int> dummy;
    
    MyQueue() {
        // s.clear();
        // dummy.clear();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int del = -1;
        if(s.size() == 0)
            return del;
        while(!s.empty()){
            dummy.push(s.top());
            s.pop();
        }
        del = dummy.top();
        dummy.pop();
        while(!dummy.empty()){
            s.push(dummy.top());
            dummy.pop();
        }
        return del;
    }
    
    /** Get the front element. */
    int peek() {
        int del = -1;
        if(s.size() == 0)
            return del;
        while(!s.empty()){
            dummy.push(s.top());
            s.pop();
        }
        del = dummy.top();
        while(!dummy.empty()){
            s.push(dummy.top());
            dummy.pop();
        }
        return del;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

