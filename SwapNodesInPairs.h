//
//  SwapNodesInPairs.h
//  
//
//  https://leetcode.com/problems/swap-nodes-in-pairs/description/
//

#ifndef SwapNodesInPairs_h
#define SwapNodesInPairs_h

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
    void print(ListNode* head)
    {
        if (head != NULL)
        {
            ListNode temp = *head;
            ListNode *iterator = &temp;
            
            while(iterator != NULL)
            {
                if (iterator->next == NULL)
                {
                    cout << iterator->val << endl;
                }
                else
                {
                    cout << iterator->val << "->";
                }
                
                iterator = iterator->next;
            }
        }
        else
        {
            cout << endl;
        }
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode *root = NULL;
        ListNode *current = NULL;
        ListNode* iterator = head;
        
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        while(true)
        {
            if (iterator == NULL || iterator->next == NULL)
            {
                break;
            }
            else
            {
                ListNode* tempNext = iterator->next;
                
                if (iterator->next->next != NULL)
                {
                    iterator->next = iterator->next->next;
                }
                else
                {
                    iterator->next = NULL;
                }
                tempNext->next = iterator;
                
                if (iterator->next == NULL)
                {
                    iterator = NULL;
                }
                else
                {
                    iterator = iterator->next;
                }
                
                if (root == NULL)
                {
                    root = tempNext;
                    current = tempNext->next;
                }
                else
                {
                    current->next = tempNext;
                    current = current->next->next;
                }
            }
        }
        
        return root;
    }
};

#endif /* SwapNodesInPairs_h */
