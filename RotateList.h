//
//  RotateList.h
//  
//
//  https://leetcode.com/problems/rotate-list/description/
//

#ifndef RotateList_h
#define RotateList_h

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
        {
            return head;
        }
        
        ListNode* temp = head;
        
        int listSize = 0;
        
        while(temp != NULL)
        {
            listSize++;
            temp = temp->next;
        }
        
        if (k % listSize == 0)
        {
            return head;
        }
        
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *it = root->next;
        
        cout << listSize << endl;
        
        int toIndex = listSize - (k % listSize);
        
        cout << toIndex << endl;
        
        for (int i = 0; i < toIndex - 1; i++)
        {
            it = it->next;
        }
        
        ListNode *root2 = new ListNode(0);
        root2->next = it->next;
        it->next = NULL;
        
        ListNode *it2 = root2->next;
        while(it2->next != NULL)
        {
            it2 = it2->next;
        }
        
        it2->next = root->next;
        
        return root2->next;
    }
};

#endif /* RotateList_h */
