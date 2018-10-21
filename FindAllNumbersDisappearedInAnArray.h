//
//  FindAllNumbersDisappearedInAnArray.h
//  
//
//  https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
//

#ifndef FindAllNumbersDisappearedInAnArray_h
#define FindAllNumbersDisappearedInAnArray_h

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] != index + 1 && nums[index] != nums[nums[index] - 1]) {
                int temp = nums[index];
                nums[index] = nums[temp - 1];
                nums[temp - 1] = temp;
            } else {
                index++;
            }
        }
        
        vector<int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                indexes.push_back(i+1);
            }
        }
        
        return indexes;
    }
};

#endif /* FindAllNumbersDisappearedInAnArray_h */
