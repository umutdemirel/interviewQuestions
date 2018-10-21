//
//  ReverseNodesInKGroups.h
//  
//
//  https://leetcode.com/problems/longest-valid-parentheses/description/
//

#ifndef ReverseNodesInKGroups_h
#define ReverseNodesInKGroups_h

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
        ListNode* temp = head;
        while(temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* root = new ListNode(-1);
        root->next = head;
        ListNode* previous = root;
        ListNode* currentStable = root->next;
        ListNode* currentIterator = root->next;
        
        while (true)
        {
            if (currentStable == NULL)
            {
                break;
            }
            bool endOfList = false;
            for (int i = 0; i < k - 1; i++)
            {
                if (currentIterator->next != NULL)
                {
                    currentIterator = currentIterator->next;
                }
                else
                {
                    endOfList = true;
                    break;
                }
            }
            if (endOfList)
            {
                break;
            }
            else
            {
                ListNode* rest = NULL;
                if (currentIterator->next != NULL)
                {
                    rest = currentIterator->next;
                }
                
                ListNode* prev = rest;
                //cout << "prev : ";
                //print(prev);
                ListNode* current = currentStable;
                //cout << "current : ";
                //print(current);
                
                for (int i = 0; i < k; i++)
                {
                    
                    ListNode* next = currentStable->next;
                    //cout << "next : ";
                    //print(next);
                    
                    current->next = prev;
                    //cout << "current : ";
                    //print(current);
                    
                    if (i < k - 1)
                    {
                        prev = current;
                        //cout << "prev : ";
                        //print(prev);
                        
                        currentStable = next;
                        //cout << "currentStable : ";
                        //print(currentStable);
                        
                        current = currentStable;
                        //cout << "current : ";
                        //print(current);
                    }
                }
                
                previous->next = current;
                //cout << "previous : ";
                //print(previous);
                
                for (int i = 0; i < k - 1; i++)
                {
                    currentIterator = currentIterator->next;
                }
                //cout << "currentIterator : ";
                //print(currentIterator);
                
                previous = currentIterator;
                //cout << "previous : ";
                //print(previous);
                
                currentStable = currentIterator->next;
                //cout << "currentStable : ";
                //print(currentStable);
                
                currentIterator = currentIterator->next;
                //cout << "currentIterator : ";
                //print(currentIterator);
            }
            
            //cout << endl;
        }
        
        return root->next;
    }
};

#endif /* ReverseNodesInKGroups_h */
