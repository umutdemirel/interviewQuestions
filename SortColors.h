//
//  SortColors.h
//  
//
//  https://leetcode.com/problems/sort-colors/description/
//

#ifndef SortColors_h
#define SortColors_h

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int twosCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                nums.insert(nums.begin(), 0);
            }
            else if (nums[i] == 2)
            {
                if (nums.size() - i == twosCount)
                {
                    break;
                }
                twosCount++;
                nums.erase(nums.begin() + i);
                nums.push_back(2);
                i--;
            }
        }
    }
};

#endif /* SortColors_h */
