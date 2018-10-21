//
//  RemoveNthNodeFromEndOfList.h
//  
//
//  https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//

#ifndef RemoveNthNodeFromEndOfList_h
#define RemoveNthNodeFromEndOfList_h

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* currentNodeToEnd = head;
        ListNode* currentNode = head;
        
        for (int i = 0; i < n; i++)
        {
            if (currentNodeToEnd->next == NULL)
            {
                head = head->next;
                return head;
            }
            currentNodeToEnd = currentNodeToEnd->next;
        }
        
        while (currentNodeToEnd->next != NULL)
        {
            currentNodeToEnd = currentNodeToEnd->next;
            currentNode = currentNode->next;
        }
        
        currentNode->next = currentNode->next->next;
        
        return head;
    }
};

#endif /* RemoveNthNodeFromEndOfList_h */
