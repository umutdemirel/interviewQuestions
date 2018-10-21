//
//  PalindromeLinkedList.h
//  
//
//  https://leetcode.com/problems/palindrome-linked-list/description/
//

#ifndef PalindromeLinkedList_h
#define PalindromeLinkedList_h

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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        if (head->next == NULL) {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        ListNode* rest = NULL;
        
        bool entered;
        while(fast->next != NULL) {
            entered = false;
            ListNode* temp = slow;
            
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
                entered = true;
            } else {
                slow = slow->next;
            }
            
            temp->next = rest;
            rest = temp;
        }
        if (entered) {
            slow = slow->next;
        }
        
        cout << "came here " << slow->val << " " << rest->val << endl;
        
        while(true) {
            if (slow == NULL && rest == NULL) {
                return true;
            } else if (slow != NULL && rest == NULL) {
                return false;
            }
            else if (slow == NULL && rest != NULL) {
                return false;
            }
            else if (slow->val != rest->val) {
                return false;
            }
            cout << slow->val << " " << rest->val << endl;
            slow = slow->next;
            rest = rest->next;
        }
    }
};

#endif /* PalindromeLinkedList_h */
