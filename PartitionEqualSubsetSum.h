//
//  PartitionEqualSubsetSum.h
//  
//
//  https://leetcode.com/problems/partition-equal-subset-sum/description/
//

#ifndef PartitionEqualSubsetSum_h
#define PartitionEqualSubsetSum_h

class Solution {
public:
    void checkRec(vector<int>& nums, vector<bool>& visited, int currentTotal, int target, bool& found) {
        if (found) {
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || (i > 0 && visited[i-1]) || (i > 0 && nums[i] != nums[i-1])) {
                if (visited[i] == false) {
                    if (currentTotal + nums[i] == target) {
                        found = true;
                        return;
                    } else if (currentTotal + nums[i] < target) {
                        vector<bool> newVisited{visited};
                        newVisited[i] = true;
                        checkRec(nums, newVisited, currentTotal + nums[i], target, found);
                    }
                }
            }
            
        }
    }
    
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <bool> visited(nums.size(), false);
        
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        
        if (total % 2 == 1) {
            return false;
        }
        
        int target = total / 2;
        int currentTotal = 0;
        
        bool found = false;
        checkRec(nums, visited, currentTotal, target, found);
        
        return found;
    }
};

#endif /* PartitionEqualSubsetSum_h */
