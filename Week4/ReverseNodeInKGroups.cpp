// 25. Reverse Nodes in k-Group (https://leetcode.com/problems/reverse-nodes-in-k-group/)
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
    
    int length(ListNode *head){
        ListNode *curr = head;
        
        int len = 0;
        while(curr){
            curr = curr->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(length(head) < k)
            return head;
        
        if(head == NULL)
            return NULL;
        
        ListNode *curr = head, *prev = NULL;
        
        for(int i=0; i<k; i++){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(curr != NULL)
            head->next = reverseKGroup(curr, k);
        return prev;
    }
};

/*
     .
NULL-1<-2<-3 ->4->5

*/