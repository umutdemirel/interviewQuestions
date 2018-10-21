//
//  SortList.h
//  
//
//  https://leetcode.com/problems/sort-list/description/
//

#ifndef SortList_h
#define SortList_h

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
        while(head != NULL)
        {
            cout << head->val << " ";
            head = head-> next;
        }
        cout << endl;
    }
    
    ListNode* splitRec(ListNode* head) {
        if (head == NULL) {
            return NULL;
        } else if (head->next == NULL) {
            return head;
        }
        
        ListNode* startHalf = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(true) {
            if (fast->next == NULL) {
                break;
            } else {
                fast = fast->next;
            }
            if (fast->next == NULL) {
                break;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        ListNode* endHalf = slow->next;
        slow->next = NULL;
        
        ListNode* sortedStartHalf = splitRec(startHalf);
        ListNode* sortedEndHalf = splitRec(endHalf);
        
        return merge(sortedStartHalf, sortedEndHalf);
    }
    
    ListNode* merge(ListNode* startHalf, ListNode* endHalf) {
        ListNode* result = new ListNode(-1);
        ListNode* resultIterator = result;
        
        ListNode* startHalfIterator = startHalf;
        ListNode* endHalfIterator = endHalf;
        
        while(true) {
            if (startHalfIterator == NULL) {
                resultIterator->next = endHalfIterator;
                break;
            }
            else if (endHalfIterator == NULL) {
                resultIterator->next = startHalfIterator;
                break;
            }
            else {
                if (startHalfIterator->val < endHalfIterator->val) {
                    resultIterator->next = startHalfIterator;
                    startHalfIterator = startHalfIterator->next;
                }
                else {
                    resultIterator->next = endHalfIterator;
                    endHalfIterator = endHalfIterator->next;
                }
                resultIterator = resultIterator->next;
            }
        }
        
        return result->next;
    }
    
    ListNode* sortList(ListNode* head) {
        return splitRec(head);
    }
};

#endif /* SortList_h */
