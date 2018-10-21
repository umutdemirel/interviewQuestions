//
//  LengthOfLastWord.h
//  
//
//  https://leetcode.com/problems/length-of-last-word/description/
//

#ifndef LengthOfLastWord_h
#define LengthOfLastWord_h

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                s.erase(s.begin() + i);
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                length = 0;
            }
            else
            {
                length++;
            }
        }
        return length;
    }
};

#endif /* LengthOfLastWord_h */
