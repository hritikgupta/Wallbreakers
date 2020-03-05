// 92. Reverse Linked List II (https://leetcode.com/problems/reverse-linked-list-ii/)
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m >= n)
            return head;
        
        ListNode *curr = head, *prev = NULL;
        int k = n-m+1;
        
        while(m > 1){
            prev = curr;
            curr = curr->next;
            m--;
        }
        ListNode *start_conn = prev;
        ListNode *start = curr;
        
        while(k--){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if(start_conn != NULL){
            start_conn->next = prev;
        }
        else head = prev;
        start->next = curr;
//         
        return head;
    }
};