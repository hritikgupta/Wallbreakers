// 206. Reverse Linked List (https://leetcode.com/problems/reverse-linked-list/)
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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)
            return NULL;
        
        ListNode *prev = NULL, *curr = head;
        
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};