//
//  ZigZagConversion.h
//  
//
//  https://leetcode.com/problems/zigzag-conversion/description/
//

#ifndef ZigZagConversion_h
#define ZigZagConversion_h

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        
        for (int i = 0; i < numRows; i++)
        {
            int index = 0;
            int increaseAmount = numRows == 1 ? 1 :(numRows - 1) * 2;
            int startingPoint = (numRows * 2) - i - 2;
            
            if (i == 0 || i == numRows - 1)
            {
                while(i + index * increaseAmount < s.length())
                {
                    result += s[i + index * increaseAmount];
                    index++;
                }
            }
            else
            {
                while(true)
                {
                    if (i + index * increaseAmount < s.length())
                    {
                        result += s[i + index * increaseAmount];
                    }
                    else
                    {
                        break;
                    }
                    
                    if (startingPoint + index * increaseAmount < s.length())
                    {
                        result += s[startingPoint + index * increaseAmount];
                    }
                    else
                    {
                        break;
                    }
                    
                    index++;
                }
            }
        }
        
        return result;
    }
};

#endif /* ZigZagConversion_h */
