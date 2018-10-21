//
//  IntersectionOfTwoLinkedList.h
//  
//
//  https://leetcode.com/problems/intersection-of-two-linked-lists/description/
//

#ifndef IntersectionOfTwoLinkedList_h
#define IntersectionOfTwoLinkedList_h

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode *headAIterator = headA;
        ListNode *headBIterator = headB;
        
        
        int countA = 1;
        int countB = 1;
        while(headAIterator->next != NULL) {
            headAIterator = headAIterator->next;
            countA++;
        }
        while(headBIterator->next != NULL) {
            headBIterator = headBIterator->next;
            countB++;
        }
        
        if (headAIterator != headBIterator) {
            return NULL;
        }
        
        ListNode *headAIterator2 = headA;
        ListNode *headBIterator2 = headB;
        if (countA > countB) {
            while(countA-countB > 0) {
                headAIterator2 = headAIterator2->next;
                countA--;
            }
        }
        if (countB > countA) {
            while(countB-countA > 0) {
                headBIterator2 = headBIterator2->next;
                countB--;
            }
        }
        
        while(headAIterator2 != headBIterator2) {
            headAIterator2 = headAIterator2->next;
            headBIterator2 = headBIterator2->next;
        }
        
        return headAIterator2;
    }
};

#endif /* IntersectionOfTwoLinkedList_h */
