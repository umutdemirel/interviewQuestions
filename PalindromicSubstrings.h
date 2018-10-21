//
//  PalindromicSubstrings.h
//  
//
//  https://leetcode.com/problems/palindromic-substrings/description/
//

#ifndef PalindromicSubstrings_h
#define PalindromicSubstrings_h

class Solution {
public:
    int countSubstrings(string s) {
        int total = s.size();
        
        for (int i = 0; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                total++;
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                total++;
                left--;
                right++;
            }
        }
        
        return total;
    }
};

#endif /* PalindromicSubstrings_h */
