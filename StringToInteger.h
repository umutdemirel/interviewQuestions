//
//  StringToInteger.h
//  
//
//  https://leetcode.com/problems/string-to-integer-atoi/description/
//

#ifndef StringToInteger_h
#define StringToInteger_h

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        
        bool digitsStarted = false;
        bool isNegative = false;
        
        vector <char> nums;
        
        for (int i = 0; i < str.length(); i++)
        {
            if (digitsStarted == false && str[i] == ' ')
            {
                continue;
            }
            else if (digitsStarted == false && str[i] != ' ' && str[i] != '-' && str[i] != '+' && ((int)str[i] < 48 || (int)str[i] > 57))
            {
                break;
            }
            else if (digitsStarted == false && str[i] == '-')
            {
                digitsStarted = true;
                isNegative = true;
            }
            else if (digitsStarted == false && str[i] == '+')
            {
                digitsStarted = true;
            }
            else if ((int)str[i] >= 48 && (int)str[i] <= 57)
            {
                nums.push_back(str[i]);
                digitsStarted = true;
            }
            else if (digitsStarted == true && ((int)str[i] < 48 || (int)str[i] > 57))
            {
                break;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == '0')
            {
                nums.erase(nums.begin());
                i--;
            }
            else
            {
                break;
            }
        }
        
        if (nums.size() > 10)
        {
            return isNegative ? INT_MIN : INT_MAX;
        }
        if (nums.size() == 10 && (int)nums[0] > 50)
        {
            return isNegative ? INT_MIN : INT_MAX;
        }
        
        int multiplier = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result += ((int)nums[i] - 48) * multiplier;
            multiplier *= 10;
            const int maxCheck = INT_MAX % ((int)pow(10,9));
            if (result > maxCheck && i > 0 && ((int)nums[i-1] - 48) >= 2)
            {
                return isNegative ? INT_MIN : INT_MAX;
            }
        }
        
        return isNegative ? result * -1 : result;
    }
};

#endif /* StringToInteger_h */
