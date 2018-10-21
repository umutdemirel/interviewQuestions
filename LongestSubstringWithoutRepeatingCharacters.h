//
//  LongestSubstringWithoutRepeatingCharacters.h
//  
//
//  https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//

#ifndef LongestSubstringWithoutRepeatingCharacters_h
#define LongestSubstringWithoutRepeatingCharacters_h

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        
        int iterator1 = 0;
        int iterator2 = 0;
        
        string currentS = "";
        
        for (int i = 0; i < s.length(); i++)
        {
            // check currentS
            for (int j = 0; j < currentS.length(); j++)
            {
                if (currentS[j] == s[i])
                {
                    currentS.erase(currentS.begin(), currentS.begin()+j+1);
                }
            }
            currentS += s[i];
            
            if (currentS.length() > longest)
            {
                longest = currentS.length();
            }
        }
        
        return longest;
    }
};

#endif /* LongestSubstringWithoutRepeatingCharacters_h */
