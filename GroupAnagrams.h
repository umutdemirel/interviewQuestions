//
//  GroupAnagrams.h
//  
//
//  https://leetcode.com/problems/group-anagrams/description/
//

#ifndef GroupAnagrams_h
#define GroupAnagrams_h

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++)
        {
            if (i == 0)
            {
                result.emplace_back(vector<string> {strs[i]});
            }
            else
            {
                bool found = false;
                for (int j = 0; j < result.size(); j++)
                {
                    if (result[j][0].size() == strs[i].size())
                    {
                        string tempStr = strs[i];
                        for (int k = 0; k < result[j][0].size(); k++)
                        {
                            for (int l = 0; l < tempStr.size(); l++)
                            {
                                if (result[j][0][k] == tempStr[l])
                                {
                                    tempStr.erase(tempStr.begin() + l);
                                    break;
                                }
                            }
                        }
                        if (tempStr.size() == 0)
                        {
                            result[j].push_back(strs[i]);
                            found = true;
                            break;
                        }
                    }
                }
                if (found == false)
                {
                    result.emplace_back(vector<string> {strs[i]});
                }
            }
        }
        
        return result;
    }
};

#endif /* GroupAnagrams_h */
