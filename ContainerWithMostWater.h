//
//  ContainerWithMostWater.h
//  
//
//  https://leetcode.com/problems/container-with-most-water/description/
//

#ifndef ContainerWithMostWater_h
#define ContainerWithMostWater_h

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i; j < height.size(); j++)
            {
                int area = min(height[i], height[j]) * (j-i);
                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
};

#endif /* ContainerWithMostWater_h */
