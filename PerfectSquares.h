//
//  PerfectSquares.h
//  
//
//  https://leetcode.com/problems/perfect-squares/description/
//

#ifndef PerfectSquares_h
#define PerfectSquares_h

class Solution {
public:
    void checkRec(int minNum, int currentValue, int n, int currentTotal, vector<int> &map) {
        for (int i = minNum; i > 0; i--) {
            int square = i * i;
            
            if (currentValue + square <= n && map[currentValue + square] > currentTotal + 1) {
                map[currentValue + square] = currentTotal + 1;
                checkRec(minNum, currentValue + square, n, currentTotal + 1, map);
            }
        }
    }
    
    
    int numSquares(int n) {
        
        int minNum = sqrt(n);
        
        vector<int> map(n + 1, n);
        
        int currentTotal = 0;
        int currentValue = 0;
        
        checkRec(minNum, currentValue, n, currentTotal, map);
        
        return map[map.size() - 1];
    }
};

#endif /* PerfectSquares_h */
