//
//  TopKFrequentElement.h
//  
//
//  https://leetcode.com/problems/top-k-frequent-elements/description/
//

#ifndef TopKFrequentElement_h
#define TopKFrequentElement_h

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]]++;
        }
        
        vector<vector<int>> freqList(nums.size() + 1, vector<int>());
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            freqList[it->second].push_back(it->first);
        }
        
        vector<int> result;
        for (int i = freqList.size() - 1; i >= 0; i--) {
            for (int j = freqList[i].size() - 1; j >= 0; j--) {
                result.push_back(freqList[i][j]);
                k--;
                if (k == 0) {
                    return result;
                }
            }
        }
    }
};

#endif /* TopKFrequentElement_h */
