//
//  DivideTwoIntegers.h
//  
//
//  https://leetcode.com/problems/divide-two-integers/description/
//

#ifndef DivideTwoIntegers_h
#define DivideTwoIntegers_h

class Solution {
public:
    string intToStr(int i)
    {
        string result = "";
        while (i != 0)
        {
            int digit = i % 10;
            char charDigit = '0' + digit;
            result = charDigit + result;
            i = (i - digit) / 10;
        }
        return result;
    }
    
    int strToInt(string str)
    {
        int result = 0;
        int multiplier = 1;
        for (int i = str.size() - 1; i >= 0 ; i--)
        {
            result += ((int)str[i] - 48) * multiplier;
            multiplier *= 10;
        }
        return result;
    }
    
    int divide(int dividend, int divisor) {
        int quotient = 0;
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == INT_MIN)
        {
            return 1;
        }
        if (dividend == INT_MIN)
        {
            if (divisor < 0)
            {
                dividend -= divisor;
                quotient++;
            }
            else if (divisor > 0)
            {
                dividend += divisor;
                quotient++;
            }
        }
        bool makeNegative = false;
        if (dividend < 0)
        {
            makeNegative = !makeNegative;
            dividend *= -1;
        }
        if (divisor < 0)
        {
            makeNegative = !makeNegative;
            divisor *= -1;
        }
        
        
        if (dividend >= 0 && divisor > 0)
        {
            while (dividend >= divisor)
            {
                string dividentStr = intToStr(dividend);
                string divisorStr = intToStr(divisor);
                
                int dividentSize = dividentStr.length();
                int divisorSize = divisorStr.length();
                
                int dividentEndIterator = divisorSize;
                int dividentStartIterator = 0;
                
                string dividentPartToCompare = dividentStr.substr(
                                                                  dividentStartIterator, dividentEndIterator - dividentStartIterator);
                
                if (strToInt(dividentPartToCompare) >= divisor)
                {
                    int dividentPartToCompareInt = strToInt(dividentPartToCompare);
                    int count = 0;
                    while (dividentPartToCompareInt >= divisor)
                    {
                        count++;
                        dividentPartToCompareInt -= divisor;
                    }
                    for (int i = 0; i < dividentSize - dividentEndIterator; i++)
                    {
                        count *= 10;
                    }
                    quotient += count;
                    
                    dividend = strToInt(intToStr(dividentPartToCompareInt) +
                                        dividentStr.substr(
                                                           dividentEndIterator, dividentSize - dividentStartIterator));
                }
                else
                {
                    if (dividentEndIterator == dividentSize)
                    {
                        break;
                    }
                    else
                    {
                        dividentEndIterator++;
                        dividentPartToCompare = dividentStr.substr(
                                                                   dividentStartIterator, dividentEndIterator - dividentStartIterator);
                        
                        int dividentPartToCompareInt = strToInt(dividentPartToCompare);
                        int count = 0;
                        while (dividentPartToCompareInt >= divisor)
                        {
                            count++;
                            dividentPartToCompareInt -= divisor;
                        }
                        for (int i = 0; i < dividentSize - dividentEndIterator; i++)
                        {
                            count *= 10;
                        }
                        
                        quotient += count;
                        
                        dividend = strToInt(intToStr(dividentPartToCompareInt) +
                                            dividentStr.substr(
                                                               dividentEndIterator, dividentSize - dividentStartIterator));
                    }
                }
            }
        }
        return makeNegative ? quotient * -1 : quotient;
    }
};

#endif /* DivideTwoIntegers_h */
