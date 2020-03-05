// 23. Merge k Sorted Lists (https://leetcode.com/problems/merge-k-sorted-lists/)
// Author: Hritik Gupta

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0; i<lists.size(); i++){
            ListNode *curr = lists[i];
            
            while(curr){
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        
        ListNode *head = new ListNode (-1);
        ListNode *curr_head = head;
        
        while(!pq.empty()){
            ListNode *temp = new ListNode(pq.top());
            pq.pop();
            curr_head->next = temp;
            curr_head = temp;
        }
        return head->next;
    }
};