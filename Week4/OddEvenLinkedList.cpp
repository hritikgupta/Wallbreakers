// 328. Odd Even Linked List (https://leetcode.com/problems/odd-even-linked-list/)
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode *even = new ListNode (-1);
        ListNode *odd = new ListNode(-1);
        
        ListNode *curr = head;
        ListNode *curr_even = even, *curr_odd = odd;
        int count = 0;
        
        while(curr){
            ListNode *temp = new ListNode(curr->val);
            if(count %2 == 0){
                curr_even->next = temp;
                curr_even = temp;
            }
            else{
                curr_odd->next = temp;
                curr_odd = temp;    
            }
            curr = curr->next;
            count++;
        }
        curr_even->next = odd->next;
        return even->next;
    }
};