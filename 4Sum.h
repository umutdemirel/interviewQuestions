//
//  4Sum.h
//  
//
//  https://leetcode.com/problems/4sum/description/
//

#ifndef _Sum_h
#define _Sum_h

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    for (int l = k+1; l < nums.size(); l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            vector <int> newCurrent{nums[i],nums[j],nums[k],nums[l]};
                            sort(newCurrent.begin(), newCurrent.end());
                            
                            bool found2 = false;
                            for (int j = 0; j < results.size(); j++)
                            {
                                bool found = true;
                                for (int k = 0; k < results[j].size(); k++)
                                {
                                    if (results[j][k] != newCurrent[k])
                                    {
                                        found = false;
                                        break;
                                    }
                                }
                                if (found == true)
                                {
                                    found2 = true;
                                    break;
                                }
                            }
                            if (found2 == false)
                            {
                                results.push_back(newCurrent);
                            }
                        }
                    }
                }
            }
        }
        
        return results;
    }
};

#endif /* _Sum_h */
