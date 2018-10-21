//
//  LargestRectangleInHistogram.h
//  
//
//  https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//

#ifndef LargestRectangleInHistogram_h
#define LargestRectangleInHistogram_h

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        for (int i = 0; i < heights.size(); i++) {
            int currentVal = heights[i];
            int currentMaxRect = currentVal;
            for (int j = i+1; j < heights.size(); j++) {
                if (heights[j] >= heights[i]) {
                    currentMaxRect += currentVal;
                }
                else {
                    break;
                }
            }
            for (int j = i-1; j >= 0; j--) {
                if (heights[j] >= heights[i]) {
                    currentMaxRect += currentVal;
                }
                else {
                    break;
                }
            }
            if (currentMaxRect > max) {
                max = currentMaxRect;
            }
        }
        return max;
    }
};

#endif /* LargestRectangleInHistogram_h */
