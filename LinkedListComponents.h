//
//  LinkedListComponents.h
//  
//
//  https://leetcode.com/problems/linked-list-components/description/
//

#ifndef LinkedListComponents_h
#define LinkedListComponents_h

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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, bool> hashMap;
        for (int val : G) {
            hashMap[val] = true;
        }
        
        int total = G.size();
        
        while(head->next != NULL) {
            if (hashMap.find(head->val) != hashMap.end()) {
                if (hashMap.find(head->next->val) != hashMap.end()) {
                    total--;
                }
            }
            head = head->next;
        }
        
        return total;
    }
};

#endif /* LinkedListComponents_h */
