//
//  PlusOne.h
//  
//
//  https://leetcode.com/problems/plus-one/description/
//

#ifndef PlusOne_h
#define PlusOne_h

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int addOne = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int total;
            if (i == digits.size() - 1)
            {
                total = digits[i] + 1 + addOne;
            }
            else
            {
                total = digits[i] + addOne;
            }
            
            if (total > 9)
            {
                addOne = 1;
            }
            else
            {
                addOne = 0;
            }
            digits[i] = total % 10;
        }
        if (addOne == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

#endif /* PlusOne_h */
