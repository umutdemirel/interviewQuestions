//
//  CombinationSumII.h
//  
//
//  https://leetcode.com/problems/combination-sum-ii/description/
//

#ifndef CombinationSumII_h
#define CombinationSumII_h

class Solution {
public:
    void combinationRec (vector <vector<int>> &result, vector <int> tempRes, vector<int> candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (target - candidates[i] == 0)
            {
                vector <int> tempRes2(tempRes);
                tempRes2.push_back(candidates[i]);
                
                sort(tempRes2.begin(), tempRes2.end());
                
                bool found = false;
                for (int i = 0; i < result.size(); i++)
                {
                    if (result[i].size() == tempRes2.size())
                    {
                        bool found2 = true;
                        for (int j = 0; j < result[i].size(); j++)
                        {
                            if (result[i][j] != tempRes2[j])
                            {
                                found2 = false;
                                break;
                            }
                        }
                        if (found2 == true)
                        {
                            found = true;
                            break;
                        }
                    }
                }
                if (found == false)
                {
                    result.push_back(tempRes2);
                }
            }
            else if (target - candidates[i] > 0)
            {
                vector <int> tempRes2(tempRes);
                tempRes2.push_back(candidates[i]);
                vector <int> tempCandidates(candidates);
                tempCandidates.erase(tempCandidates.begin() + i);
                
                combinationRec(result, tempRes2, tempCandidates, target - candidates[i]);
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <vector<int>> result;
        vector <int> tempRes;
        
        combinationRec(result, tempRes, candidates, target);
        
        return result;
    }
};

#endif /* CombinationSumII_h */
