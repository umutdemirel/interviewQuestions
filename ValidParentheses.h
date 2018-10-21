//
//  ValidParentheses.h
//  
//
//  https://leetcode.com/problems/valid-parentheses/description/
//

#ifndef ValidParentheses_h
#define ValidParentheses_h

class Solution {
public:
    bool isValid(string s) {
        vector<char> p;
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (p.size() == 0 && (c == ')' || c == ']' || c == '}' ))
            {
                return false;
            }
            else if (p.size() == 0)
            {
                p.push_back(c);
            }
            else
            {
                if (c == ')' && p[p.size()-1] == '(')
                {
                    p.pop_back();
                }
                else if (c == ']' && p[p.size()-1] == '[')
                {
                    p.pop_back();
                }
                else if (c == '}' && p[p.size()-1] == '{')
                {
                    p.pop_back();
                }
                else if (c == '(' || c == '[' || c == '{')
                {
                    p.push_back(c);
                }
                else
                {
                    return false;
                }
            }
        }
        
        if (p.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif /* ValidParentheses_h */
