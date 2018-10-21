//
//  LongestConsequtiveSequence.h
//  
//
//  https://leetcode.com/problems/longest-consecutive-sequence/description/
//

#ifndef LongestConsequtiveSequence_h
#define LongestConsequtiveSequence_h

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return 1;
        }
        
        map<int, bool> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap.insert(pair<int, bool>(nums[i], true));
        }
        
        int max = 1;
        int current = 0;
        int currentVal = INT_MIN;
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            if (current == 0) {
                currentVal = it->first;
                current++;
            }
            else if (it->first == currentVal + 1) {
                currentVal = it->first;
                current++;
                if (current > max) {
                    max = current;
                }
            }
            else {
                currentVal = it->first;
                current = 1;
            }
        }
        
        return max;
    }
};

#endif /* LongestConsequtiveSequence_h */
