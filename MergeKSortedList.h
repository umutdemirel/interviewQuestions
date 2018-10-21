//
//  MergeKSortedList.h
//  
//
//  https://leetcode.com/problems/merge-k-sorted-lists/description/
//

#ifndef MergeKSortedList_h
#define MergeKSortedList_h

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* resultIterator = NULL;
        
        while(true)
        {
            int min = INT_MAX;
            int minIndex = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != NULL && lists[i]->val < min)
                {
                    min = lists[i]->val;
                    minIndex = i;
                }
            }
            
            if (min == INT_MAX)
            {
                break;
            }
            else
            {
                cout << lists[minIndex]->val << endl;
                if (result == NULL)
                {
                    result = lists[minIndex];
                    resultIterator = result;
                }
                else
                {
                    resultIterator->next = lists[minIndex];
                    resultIterator = resultIterator->next;
                }
                
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        
        return result;
    }
};

#endif /* MergeKSortedList_h */
