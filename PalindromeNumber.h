//
//  PalindromeNumber.h
//  
//
//  https://leetcode.com/problems/palindrome-number/description/
//

#ifndef PalindromeNumber_h
#define PalindromeNumber_h

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
        {
            return true;
        }
        if (x < 0)
        {
            return false;
        }
        if (x % 10 == 0)
        {
            return false;
        }
        
        vector <int> digits;
        
        int tempNum = x;
        while (tempNum > 0)
        {
            int digit = tempNum % 10;
            digits.push_back(digit);
            tempNum = (tempNum - digit) / 10;
        }
        
        int iterator = 0;
        int iterator2 = digits.size() - 1;
        
        while (true)
        {
            if (digits[iterator] != digits[iterator2])
            {
                return false;
            }
            else
            {
                iterator++;
                iterator2--;
                if (iterator >= iterator2)
                {
                    return true;
                }
            }
        }
    }
};

#endif /* PalindromeNumber_h */
