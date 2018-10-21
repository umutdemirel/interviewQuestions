//
//  LongestCommonPrefix.h
//  
//
//  https://leetcode.com/problems/longest-common-prefix/description/
//

#ifndef LongestCommonPrefix_h
#define LongestCommonPrefix_h

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        if (strs.size() == 0)
        {
            return result;
        }
        
        int iterator = 0;
        while (true)
        {
            bool found = true;
            char c;
            if (strs[0].length() > iterator)
            {
                c = strs[0][iterator];
            }
            else
            {
                return result;
            }
            
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i].length() > iterator && strs[i][iterator] != c)
                {
                    return result;
                }
                if (strs[i].length() == iterator)
                {
                    return result;
                }
            }
            
            result += c;
            
            iterator++;
        }
        
    }
};

#endif /* LongestCommonPrefix_h */
