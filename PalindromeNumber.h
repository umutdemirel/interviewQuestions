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
        
        int tempNum = x;
        int constructedNum = 0;
        while (tempNum > 0)
        {
            constructedNum *= 10;
            int digit = tempNum % 10;
            tempNum = (tempNum - digit) / 10;
            constructedNum += digit;
        }
        
        return constructedNum == x;
    }
};

#endif /* PalindromeNumber_h */
