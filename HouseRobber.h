//
//  HouseRobber.h
//  
//
//  https://leetcode.com/problems/house-robber/description/
//

#ifndef HouseRobber_h
#define HouseRobber_h

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int maxValue = nums[nums.size() - 1];
        vector <int> dynamic(nums.size(), 0);
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            dynamic[i] = max(nums[i], dynamic[i]);
            maxValue = max(maxValue, dynamic[i]);
            for (int j = i - 2; j >= 0; j--) {
                dynamic[j] = max(nums[j] + dynamic[i], dynamic[j]);
                maxValue = max(maxValue, dynamic[j]);
            }
            /*
             for (int k = 0; k < dynamic.size(); k++) {
             cout << dynamic[k] << " ";
             }
             cout << endl;
             */
        }
        
        return maxValue;
    }
};

#endif /* HouseRobber_h */
