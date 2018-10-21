//
//  CountingBits.h
//  
//
//  https://leetcode.com/problems/counting-bits/description/
//

#ifndef CountingBits_h
#define CountingBits_h

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bitList;
        
        bitList.push_back(0);
        if (num == 0) {
            return bitList;
        }
        
        bitList.push_back(1);
        if (num == 1) {
            return bitList;
        }
        
        int count = 2;
        int multCount = 0;
        int multValue = 2;
        
        while(count <= num) {
            bitList.push_back(1 + bitList[multCount]);
            count++;
            multCount++;
            if (multCount == multValue) {
                multCount = 0;
                multValue *= 2;
            }
        }
        
        return bitList;
    }
};

#endif /* CountingBits_h */
