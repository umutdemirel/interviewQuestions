//
//  SingleNumber.h
//  
//
//  https://leetcode.com/problems/single-number/description/
//

#ifndef SingleNumber_h
#define SingleNumber_h

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,bool> hashMap;
        for(int i = 0; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) == hashMap.end()) {
                hashMap[nums[i]] = true;
            }
            else
            {
                hashMap.erase(nums[i]);
            }
        }
        return hashMap.begin()->first;
    }
};

#endif /* SingleNumber_h */
