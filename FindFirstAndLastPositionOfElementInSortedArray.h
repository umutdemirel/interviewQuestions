//
//  FindFirstAndLastPositionOfElementInSortedArray.h
//  
//
//  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//

#ifndef FindFirstAndLastPositionOfElementInSortedArray_h
#define FindFirstAndLastPositionOfElementInSortedArray_h

class Solution {
public:
    void searchRangeRec(vector<int>& result, vector<int>& nums, int startIndex, int endIndex, int target)
    {
        if (endIndex - startIndex <= 0)
        {
            return;
        }
        
        int iterator;
        if (endIndex - startIndex == 1)
        {
            iterator = startIndex + ((endIndex+1 - startIndex) / 2);
        }
        else
        {
            iterator = startIndex + ((endIndex - startIndex) / 2);
        }
        
        cout << startIndex << " " << iterator << " " << endIndex << endl;
        
        if (nums[iterator] == target)
        {
            if (iterator < result[0])
            {
                result[0] = iterator;
            }
            if (iterator > result[1])
            {
                result[1] = iterator;
            }
            
            if (endIndex - startIndex == 1)
            {
                if (nums[iterator-1] == target)
                {
                    if (iterator - 1 < result[0])
                    {
                        result[0] = iterator - 1;
                    }
                    if (iterator - 1 > result[1])
                    {
                        result[1] = iterator - 1;
                    }
                }
                return;
            }
            searchRangeRec(result, nums, startIndex, startIndex + ((endIndex - startIndex) / 2), target);
            searchRangeRec(result, nums, startIndex + ((endIndex - startIndex) / 2), endIndex, target);
        }
        else if (nums[iterator] > target)
        {
            if (endIndex - startIndex == 1)
            {
                if (nums[iterator-1] == target)
                {
                    if (iterator - 1 < result[0])
                    {
                        result[0] = iterator - 1;
                    }
                    if (iterator - 1 > result[1])
                    {
                        result[1] = iterator - 1;
                    }
                }
                return;
            }
            searchRangeRec(result, nums, startIndex, startIndex + ((endIndex - startIndex) / 2), target);
        }
        else if (nums[iterator] < target)
        {
            if (endIndex - startIndex == 1)
            {
                if (nums[iterator-1] == target)
                {
                    if (iterator - 1 < result[0])
                    {
                        result[0] = iterator - 1;
                    }
                    if (iterator - 1 > result[1])
                    {
                        result[1] = iterator - 1;
                    }
                }
                return;
            }
            searchRangeRec(result, nums, startIndex + ((endIndex - startIndex) / 2), endIndex, target);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingIndex = INT_MAX;
        int endIndex = INT_MIN;
        vector<int> result;
        result.push_back(startingIndex);
        result.push_back(endIndex);
        
        int limitStart = 0;
        int limitEnd = nums.size() - 1;
        int iterator = (limitEnd - limitStart) / 2;
        
        searchRangeRec(result, nums, 0, nums.size() - 1, target);
        
        if (result[0] == INT_MAX)
        {
            result[0] = -1;
            result[1] = -1;
        }
        if (nums.size() == 1 && nums[0] == target)
        {
            result[0] = 0;
            result[1] = 0;
        }
        return result;
    }
};

#endif /* FindFirstAndLastPositionOfElementInSortedArray_h */
