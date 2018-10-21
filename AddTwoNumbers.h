//
//  AddTwoNumbers.h
//  
//
//  https://leetcode.com/problems/add-two-numbers/description/
//

#ifndef AddTwoNumbers_h
#define AddTwoNumbers_h

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *currentNode = result;
        
        bool greaterThan9 = false;
        while (l1 != NULL || l2 != NULL)
        {
            int v1 = 0;
            int v2 = 0;
            if (l1 != NULL)
            {
                v1 = l1->val;
            }
            if (l2 != NULL)
            {
                v2 = l2->val;
            }
            
            int tempValue = v1 + v2;
            if (greaterThan9)
            {
                tempValue++;
            }
            
            currentNode->val = tempValue % 10;
            
            if (tempValue > 9)
            {
                greaterThan9 = true;
            }
            else
            {
                greaterThan9 = false;
            }
            
            if (l1 != NULL)
            {
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                l2 = l2->next;
            }
            
            if (l1 != NULL || l2 != NULL)
            {
                currentNode->next = new ListNode(0);
                currentNode = currentNode->next;
            }
        }
        
        if (greaterThan9)
        {
            currentNode->next = new ListNode(0);
            currentNode = currentNode->next;
            currentNode->val++;
        }
        
        return result;
    }
};

#endif /* AddTwoNumbers_h */
