//
//  MergeTwoSortedLists.h
//  
//
//  https://leetcode.com/problems/merge-two-sorted-lists/description/
//

#ifndef MergeTwoSortedLists_h
#define MergeTwoSortedLists_h

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        
        ListNode* l1Rest = l1;
        ListNode* l2Rest = l2;
        ListNode* rootNode;
        ListNode* resultingNode;
        
        if (l1->val < l2->val)
        {
            rootNode = l1;
            l1Rest = l1->next;
        }
        else
        {
            rootNode = l2;
            l2Rest = l2->next;
        }
        
        resultingNode = rootNode;
        
        while(true)
        {
            if (l1Rest == NULL)
            {
                resultingNode->next = l2Rest;
                break;
            }
            if (l2Rest == NULL)
            {
                resultingNode->next = l1Rest;
                break;
            }
            
            if (l1Rest->val < l2Rest->val)
            {
                resultingNode->next = l1Rest;
                resultingNode = resultingNode->next;
                l1Rest = l1Rest->next;
            }
            else
            {
                resultingNode->next = l2Rest;
                resultingNode = resultingNode->next;
                l2Rest = l2Rest->next;
            }
        }
        
        return rootNode;
    }
};

#endif /* MergeTwoSortedLists_h */
