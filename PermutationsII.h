//
//  PermutationsII.h
//  
//
//  https://leetcode.com/problems/permutations-ii/description/
//

#ifndef PermutationsII_h
#define PermutationsII_h

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
            bool found = false;
            for (int j = 0; j < rest.size(); j++)
            {
                if (i != j)
                {
                    if (rest[i] == rest[j] && j > i)
                    {
                        found = true;
                        break;
                    }
                }
            }
            if (found == false)
            {
                vector<int> newCurrent(current);
                newCurrent.push_back(rest[i]);
                vector <int> newRest(rest);
                newRest.erase(newRest.begin()+i);
                permuteRec(result, newCurrent, newRest);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        permuteRec(result, current, nums);
        return result;
    }
};

#endif /* PermutationsII_h */
