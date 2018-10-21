//
//  LetterCombinationOfAPhoneNumber.h
//  
//
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
//

#ifndef LetterCombinationOfAPhoneNumber_h
#define LetterCombinationOfAPhoneNumber_h

class Solution {
public:
    
    void letterComb(string digits, string currentStr, vector<string> *results)
    {
        if (digits.length() == 0)
        {
            results->push_back(currentStr);
        }
        else
        {
            char digit = digits[0];
            digits.erase(digits.begin());
            if (digit == '2')
            {
                letterComb(digits, currentStr + 'a', results);
                letterComb(digits, currentStr + 'b', results);
                letterComb(digits, currentStr + 'c', results);
            }
            else if (digit == '3')
            {
                letterComb(digits, currentStr + 'd', results);
                letterComb(digits, currentStr + 'e', results);
                letterComb(digits, currentStr + 'f', results);
            }
            else if (digit == '4')
            {
                letterComb(digits, currentStr + 'g', results);
                letterComb(digits, currentStr + 'h', results);
                letterComb(digits, currentStr + 'i', results);
            }
            else if (digit == '5')
            {
                letterComb(digits, currentStr + 'j', results);
                letterComb(digits, currentStr + 'k', results);
                letterComb(digits, currentStr + 'l', results);
            }
            else if (digit == '6')
            {
                letterComb(digits, currentStr + 'm', results);
                letterComb(digits, currentStr + 'n', results);
                letterComb(digits, currentStr + 'o', results);
            }
            else if (digit == '7')
            {
                letterComb(digits, currentStr + 'p', results);
                letterComb(digits, currentStr + 'q', results);
                letterComb(digits, currentStr + 'r', results);
                letterComb(digits, currentStr + 's', results);
            }
            else if (digit == '8')
            {
                letterComb(digits, currentStr + 't', results);
                letterComb(digits, currentStr + 'u', results);
                letterComb(digits, currentStr + 'v', results);
            }
            else if (digit == '9')
            {
                letterComb(digits, currentStr + 'w', results);
                letterComb(digits, currentStr + 'x', results);
                letterComb(digits, currentStr + 'y', results);
                letterComb(digits, currentStr + 'z', results);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.length() == 0)
        {
            return results;
        }
        letterComb(digits, "", &results);
        return results;
    }
};

#endif /* LetterCombinationOfAPhoneNumber_h */
