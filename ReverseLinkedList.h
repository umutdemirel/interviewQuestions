//
//  ReverseLinkedList.h
//  
//
//  https://leetcode.com/problems/reverse-linked-list/description/
//

#ifndef ReverseLinkedList_h
#define ReverseLinkedList_h

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
    ListNode* reverseRec(ListNode* node) {
        if (node->next == NULL) {
            return node;
        }
        ListNode* reversedList = reverseRec(node->next);
        node->next = NULL;
        
        ListNode* iterator = reversedList;
        while(iterator->next != NULL) {
            iterator = iterator->next;
        }
        iterator->next = node;
        return reversedList;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        return reverseRec(head);
    }
};

#endif /* ReverseLinkedList_h */
