//
//  HammingDistance.h
//  
//
//  https://leetcode.com/problems/hamming-distance/description/
//

#ifndef HammingDistance_h
#define HammingDistance_h

class Solution {
public:
    int hammingDistance(int x, int y) {
        string binaryX = bitset<32>(x).to_string();
        string binaryY = bitset<32>(y).to_string();
        
        int total = 0;
        for (int i = 0; i < binaryX.size(); i++) {
            if (binaryX[i] != binaryY[i]) {
                total++;
            }
        }
        
        return total;
    }
};

#endif /* HammingDistance_h */
