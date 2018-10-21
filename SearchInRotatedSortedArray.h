//
//  SearchInRotatedSortedArray.h
//  
//
//  https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//

#ifndef SearchInRotatedSortedArray_h
#define SearchInRotatedSortedArray_h

class Solution {
public:
    void searchRec(vector<int>& nums, int target, int &minIndex, int &minValue, int leftIndex, int rightIndex)
    {
        //cout << leftIndex << " " << rightIndex << endl;
        if (leftIndex >= rightIndex)
        {
            if (nums[leftIndex] < minValue)
            {
                minValue = nums[leftIndex];
                minIndex = leftIndex;
            }
            return;
        }
        
        int index = (rightIndex + leftIndex) / 2;
        if (nums[index] < minValue)
        {
            minValue = nums[index];
            minIndex = index;
        }
        
        //cout << index << endl;
        if (nums[rightIndex] < nums[index])
        {
            leftIndex = index + 1;
            rightIndex = rightIndex;
            searchRec(nums, target, minIndex, minValue, leftIndex, rightIndex);
        }
        else
        {
            leftIndex = leftIndex;
            rightIndex = index - 1;
            searchRec(nums, target, minIndex, minValue, leftIndex, rightIndex);
        }
    }
    
    void binarySearch(vector<int>& nums, int target, int &targetIndex, int leftIndex, int rightIndex)
    {
        if (leftIndex >= rightIndex)
        {
            if (nums[leftIndex] == target)
            {
                targetIndex = leftIndex;
            }
            return;
        }
        
        int index = (rightIndex + leftIndex) / 2;
        //cout << index << endl;
        if (nums[index] == target)
        {
            targetIndex = index;
            return;
        }
        else if (nums[index] < target)
        {
            leftIndex = index + 1;
            rightIndex = rightIndex;
            binarySearch(nums, target, targetIndex, leftIndex, rightIndex);
        }
        else if (nums[index] > target)
        {
            leftIndex = leftIndex;
            rightIndex = index - 1;
            binarySearch(nums, target, targetIndex, leftIndex, rightIndex);
        }
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return -1;
        }
        
        int minIndex = -1;
        int minValue = INT_MAX;
        
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        
        searchRec(nums, target, minIndex, minValue, leftIndex, rightIndex);
        
        cout << minIndex << endl;
        
        int targetIndex = -1;
        if (minIndex == 0)
        {
            binarySearch(nums, target, targetIndex, leftIndex, rightIndex);
        }
        else if (target > nums[rightIndex])
        {
            binarySearch(nums, target, targetIndex, leftIndex, minIndex - 1);
        }
        else if (target <= nums[rightIndex])
        {
            binarySearch(nums, target, targetIndex, minIndex, rightIndex);
        }
        
        return targetIndex;
    }
};

#endif /* SearchInRotatedSortedArray_h */
