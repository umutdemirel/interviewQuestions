//
//  ImplementStrStr.h
//  
//
//  https://leetcode.com/problems/implement-strstr/description/
//

#ifndef ImplementStrStr_h
#define ImplementStrStr_h

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == "" && needle == "")
        {
            return 0;
        }
        for (int i = 0; i < haystack.length(); i++)
        {
            bool found = true;
            for (int j = 0; j < needle.length(); j++)
            {
                if (i+j < haystack.length())
                {
                    if (haystack[i+j] != needle[j])
                    {
                        found = false;
                        break;
                    }
                }
                else
                {
                    found = false;
                    break;
                }
            }
            if (found == true)
            {
                return i;
            }
        }
        return -1;
    }
};

#endif /* ImplementStrStr_h */
