//
//  ProductOfArrayExceptSelf.h
//  
//
//  Created by umut demirel on 21.10.2018.
//

#ifndef ProductOfArrayExceptSelf_h
#define ProductOfArrayExceptSelf_h

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int hasZero = false;
        int has2Zero = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                total *= nums[i];
            } else {
                if (hasZero) {
                    has2Zero = true;
                    break;
                }
                hasZero = true;
            }
        }
        
        if (has2Zero) {
            return vector<int>(nums.size(), 0);
        }
        
        vector<int> result(nums.size(), total);
        
        for (int i = 0; i < result.size(); i++) {
            if (nums[i] != 0) {
                if (hasZero) {
                    result[i] = 0;
                } else {
                    result[i] = result[i] / nums[i];
                }
            }
        }
        
        return result;
    }
};

#endif /* ProductOfArrayExceptSelf_h */
