//
//  TrappingRainWater.h
//  
//
//  https://leetcode.com/problems/trapping-rain-water/description/
//

#ifndef TrappingRainWater_h
#define TrappingRainWater_h

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
        {
            return 0;
        }
        
        int total = 0;
        
        int tallest1 = INT_MIN;
        int tallest1Index = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= tallest1)
            {
                tallest1 = height[i];
                tallest1Index = i;
            }
        }
        
        int tallest2 = INT_MIN;
        int tallest2Index = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (i != tallest1Index)
            {
                if (height[i] > tallest2)
                {
                    tallest2 = height[i];
                    tallest2Index = i;
                }
            }
        }
        
        int minValue = min (tallest1Index, tallest2Index);
        int maxValue = max (tallest1Index, tallest2Index);
        
        for (int i = minValue; i < maxValue; i++)
        {
            int minTallWall = min(tallest1, tallest2);
            if (minTallWall > height[i])
            {
                total += (minTallWall - height[i]);
            }
        }
        
        vector <int> rest1;
        for (int i = 0; i < minValue + 1; i++)
        {
            rest1.push_back(height[i]);
        }
        
        vector <int> rest2;
        for (int i = maxValue; i < height.size(); i++)
        {
            rest2.push_back(height[i]);
        }
        
        return total + trap(rest1) + trap(rest2);
    }
};

#endif /* TrappingRainWater_h */
