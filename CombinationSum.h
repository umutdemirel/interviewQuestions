//
//  CombinationSum.h
//  
//
//  https://leetcode.com/problems/combination-sum/description/
//

#ifndef CombinationSum_h
#define CombinationSum_h

class Solution {
public:
    
    void combSum(vector<vector<int>> *result, vector<int> currentResult, vector<int> candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (currentResult.size() > 0)
            {
                if (currentResult[currentResult.size() - 1] > candidates[i])
                {
                    continue;
                }
            }
            if (target == candidates[i])
            {
                currentResult.push_back(candidates[i]);
                result->push_back(currentResult);
            }
            else if (target > candidates[i])
            {
                vector <int> tempResult;
                for (int j = 0; j < currentResult.size(); j++)
                {
                    tempResult.push_back(currentResult[j]);
                }
                tempResult.push_back(candidates[i]);
                combSum(result, tempResult, candidates, target - candidates[i]);
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentResult;
        
        sort(candidates.begin(), candidates.end());
        combSum(&result, currentResult, candidates, target);
        
        return result;
    }
};

#endif /* CombinationSum_h */
