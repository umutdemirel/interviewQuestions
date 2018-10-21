//
//  IntegerToRoman.h
//  
//
//  https://leetcode.com/problems/integer-to-roman/description/
//

#ifndef IntegerToRoman_h
#define IntegerToRoman_h

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        
        vector <int> digits;
        
        int tempNum = num;
        while(tempNum > 0)
        {
            int digit = tempNum % 10;
            digits.push_back(digit);
            tempNum = (tempNum - digit) / 10;
        }
        
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (i == 3)
            {
                for (int j = 0; j < digits[i]; j++)
                {
                    result += 'M';
                }
            }
            else if (i == 2)
            {
                if (digits[i] < 4)
                {
                    for (int j = 0; j < digits[i]; j++)
                    {
                        result += 'C';
                    }
                }
                else if (digits[i] < 5)
                {
                    result += "CD";
                }
                else if (digits[i] < 9)
                {
                    result += 'D';
                    for (int j = 0; j < digits[i] - 5; j++)
                    {
                        result += 'C';
                    }
                }
                else if (digits[i] == 9)
                {
                    result += "CM";
                }
            }
            else if (i == 1)
            {
                if (digits[i] < 4)
                {
                    for (int j = 0; j < digits[i]; j++)
                    {
                        result += 'X';
                    }
                }
                else if (digits[i] < 5)
                {
                    result += "XL";
                }
                else if (digits[i] < 9)
                {
                    result += 'L';
                    for (int j = 0; j < digits[i] - 5; j++)
                    {
                        result += 'X';
                    }
                }
                else if (digits[i] == 9)
                {
                    result += "XC";
                }
            }
            else if (i == 0)
            {
                if (digits[i] < 4)
                {
                    for (int j = 0; j < digits[i]; j++)
                    {
                        result += 'I';
                    }
                }
                else if (digits[i] < 5)
                {
                    result += "IV";
                }
                else if (digits[i] < 9)
                {
                    result += 'V';
                    for (int j = 0; j < digits[i] - 5; j++)
                    {
                        result += 'I';
                    }
                }
                else if (digits[i] == 9)
                {
                    result += "IX";
                }
            }
        }
        
        return result;
    }
};

#endif /* IntegerToRoman_h */
