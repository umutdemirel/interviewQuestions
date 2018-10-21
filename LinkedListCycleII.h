//
//  LinkedListCycleII.h
//  
//
//  https://leetcode.com/problems/linked-list-cycle-ii/description/
//

#ifndef LinkedListCycleII_h
#define LinkedListCycleII_h

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
    ListNode *detectCycle(ListNode *head) {
        vector <ListNode *> nodes;
        
        ListNode *iterator = head;
        
        while (iterator != NULL)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] == iterator)
                {
                    return nodes[i];
                }
            }
            ListNode *newItem = iterator;
            nodes.push_back(newItem);
            
            iterator = iterator->next;
        }
        
        return NULL;
    }
};

#endif /* LinkedListCycleII_h */
