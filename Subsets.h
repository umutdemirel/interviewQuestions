//
//  Subsets.h
//  
//
//  https://leetcode.com/problems/subsets/description/
//

#ifndef Subsets_h
#define Subsets_h

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            int tempSize = result.size();
            for (int j = 0; j < tempSize; j++)
            {
                vector<int> tempElement = result[j];
                tempElement.push_back(nums[i]);
                result.push_back(tempElement);
            }
        }
        return result;
    }
};

#endif /* Subsets_h */
