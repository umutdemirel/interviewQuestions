//
//  Sqrtx.h
//  
//
//  https://leetcode.com/problems/sqrtx/description/
//

#ifndef Sqrtx_h
#define Sqrtx_h

class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        while(i <= 46340 && i*i <= x)
        {
            i++;
        }
        return i-1;
    }
};

#endif /* Sqrtx_h */
