//
//  ClimbingStairs.h
//  
//
//  https://leetcode.com/problems/climbing-stairs/description/
//

#ifndef ClimbingStairs_h
#define ClimbingStairs_h

class Solution {
public:
    int climbStairs(int n) {
        int total = 0;
        int previous = 0;
        int now = 1;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                total = previous + now;
                previous = 1;
                now = 1;
            }
            else
            {
                total = previous + now;
                previous = now;
                now = total;
            }
        }
        
        return total;
    }
};

#endif /* ClimbingStairs_h */
