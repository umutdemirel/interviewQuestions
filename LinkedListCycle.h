//
//  LinkedListCycle.h
//  
//
//  https://leetcode.com/problems/linked-list-cycle/description/
//

#ifndef LinkedListCycle_h
#define LinkedListCycle_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector <ListNode *> nodes;
        
        ListNode *iterator = head;
        
        while (iterator != NULL)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] == iterator)
                {
                    return true;
                }
            }
            ListNode *newItem = iterator;
            nodes.push_back(newItem);
            
            iterator = iterator->next;
        }
        
        return false;
    }
};

#endif /* LinkedListCycle_h */
