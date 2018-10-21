//
//  TwoSums.h
//  
//
//  https://leetcode.com/problems/two-sum/description/
//

#ifndef TwoSums_h
#define TwoSums_h

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        unordered_map<int, int> hashMap;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.find(target - nums[i]) != hashMap.end()) {
                result.push_back(hashMap[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            hashMap[nums[i]] = i;
        }
    }
};

#endif /* TwoSums_h */
