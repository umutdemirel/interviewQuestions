//
//  MaximumProductSubarray.h
//  
//
//  https://leetcode.com/problems/maximum-product-subarray/description/
//

#ifndef MaximumProductSubarray_h
#define MaximumProductSubarray_h

class Solution {
public:
    
    
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        
        int total = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                total *= nums[j];
                if (total > max)
                {
                    max = total;
                }
            }
            total = 1;
        }
        
        return max;
    }
};

#endif /* MaximumProductSubarray_h */
