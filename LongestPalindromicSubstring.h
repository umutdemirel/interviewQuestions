//
//  LongestPalindromicSubstring.h
//  
//
//  https://leetcode.com/problems/longest-palindromic-substring/description/
//

#ifndef LongestPalindromicSubstring_h
#define LongestPalindromicSubstring_h

class Solution {
public:
    string longestPalindrome(string s) {
        
        int longestSize = 0;
        string longestStr = "";
        
        if (s.length() < 3)
        {
            longestStr = s[0];
        }
        
        for (int i = 0; i < s.length(); i++)
        {
            //even check
            int iterator = 0;
            int longestTempSize = 0;
            string longestTempStr = "";
            while(i - iterator >= 0 && i + iterator < s.size())
            {
                if (s[i - iterator] == s[i + 1 + iterator])
                {
                    longestTempSize += 2;
                    longestTempStr = s[i - iterator] + longestTempStr + s[i + 1 + iterator];
                }
                else
                {
                    break;
                }
                iterator++;
            }
            
            if (longestTempSize > longestSize)
            {
                longestSize = longestTempSize;
                longestStr = longestTempStr;
            }
            
            //odd check
            iterator = 1;
            longestTempSize = 1;
            longestTempStr = s[i];
            while(i - iterator >= 0 && i + iterator < s.size())
            {
                if (s[i - iterator] == s[i + iterator])
                {
                    longestTempSize += 2;
                    longestTempStr = s[i - iterator] + longestTempStr + s[i + iterator];
                }
                else
                {
                    break;
                }
                iterator++;
            }
            
            if (longestTempSize > longestSize)
            {
                longestSize = longestTempSize;
                longestStr = longestTempStr;
            }
        }
        
        return longestStr;
    }
};

#endif /* LongestPalindromicSubstring_h */
