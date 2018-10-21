//
//  PowXN.h
//  
//
//  https://leetcode.com/problems/powx-n/description/
//

#ifndef PowXN_h
#define PowXN_h

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1;
        }
        if (x == 1)
        {
            return 1;
        }
        if (x == -1)
        {
            if (n % 2 == 1)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        
        x = n < 0 ? 1 / x : x;
        double result = x;
        
        for (int i = 0; i < abs(n) - 1; i++)
        {
            result *= x;
            if (result == 0)
            {
                break;
            }
        }
        
        return result;
    }
};

#endif /* PowXN_h */
