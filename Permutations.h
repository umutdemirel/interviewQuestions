//
//  Permutations.h
//  
//
//  https://leetcode.com/problems/permutations/description/
//

#ifndef Permutations_h
#define Permutations_h

class Solution {
public:
    void permuteRec(vector<vector<int>> &result, vector<int> current, vector<int> rest)
    {
        if (rest.size() == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = 0 ; i < rest.size(); i++)
        {
            vector<int> newCurrent(current);
            newCurrent.push_back(rest[i]);
            vector <int> newRest(rest);
            newRest.erase(newRest.begin()+i);
            permuteRec(result, newCurrent, newRest);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        permuteRec(result, current, nums);
        return result;
    }
};

#endif /* Permutations_h */
