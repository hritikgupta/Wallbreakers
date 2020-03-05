// 160. Intersection of Two Linked Lists (https://leetcode.com/problems/intersection-of-two-linked-lists/)
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
    
    int getLength(ListNode *head){
        ListNode *curr = head;
        int len = 0;
        
        while(curr){
            len++;
            curr = curr->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        int diff = abs(lenA-lenB);
        
        if(lenA > lenB)
            return getIntersectionNode(headB, headA);
        
        ListNode *currA = headA, *currB = headB;
        
        while(diff--)
            currB = currB->next;
        
        while(currA && currB){
            if(currA == currB)
                return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};