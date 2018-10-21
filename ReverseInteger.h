//
//  ReverseInteger.h
//  
//
//  https://leetcode.com/problems/reverse-integer/description/
//

#ifndef ReverseInteger_h
#define ReverseInteger_h

class Solution {
public:
    int reverse(int x) {
        vector <int> nums;
        
        bool isNegative = x < 0 ? true : false;
        x = isNegative ? x * -1 : x;
        
        int multiplier = 10;
        while (true)
        {
            nums.push_back((x % multiplier - x % (multiplier / 10)) / (multiplier / 10));
            
            if (x / multiplier < 10)
            {
                if (x > 9)
                {
                    nums.push_back(x / multiplier);
                }
                break;
            }
            else
            {
                multiplier *= 10;
            }
        }
        
        // construct the number
        int number = 0;
        int multiplier2 = 1;
        
        for (int i = 0; i < nums.size() - 1; i++)
        {
            multiplier2 *= 10;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 && nums[i] == 0)
            {
                multiplier2 = multiplier2 / 10;
            }
            else
            {
                for (int j = 0; j < nums[i]; j++)
                {
                    number += multiplier2;
                    if (number < 0)
                    {
                        return 0;
                    }
                }
                
                
                multiplier2 = multiplier2 / 10;
                
                
                if (number < 0)
                {
                    return 0;
                }
            }
        }
        
        if (isNegative)
        {
            return -1 * number;
        }
        else
        {
            return number;
        }
    }
};

#endif /* ReverseInteger_h */
