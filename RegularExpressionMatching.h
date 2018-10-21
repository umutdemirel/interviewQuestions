//
//  RegularExpressionMatching.h
//  
//
//  https://leetcode.com/problems/regular-expression-matching/description/
//

#ifndef RegularExpressionMatching_h
#define RegularExpressionMatching_h

class Solution {
public:
    bool isMatch(string s, string p) {
        bool result = false;
        isMatchRec(s, p, &result);
        return result;
    }
    
    void isMatchRec(string s, string p, bool *found) {
        if (*found == true)
        {
            return;
        }
        if (s.length() == 0 && p.length() == 0)
        {
            *found = true;
            return;
        }
        else if (p.length() == 0)
        {
            return;
        }
        char c = p[0];
        
        if (p.length() > 1)
        {
            char nc = p[1];
            
            if (nc == '*')
            {
                p.erase(p.begin());
                p.erase(p.begin());
                isMatchRec(s, p, found);
                if (c == '.')
                {
                    while (s.length() > 0)
                    {
                        s.erase(s.begin());
                        isMatchRec(s, p, found);
                    }
                }
                else
                {
                    while (s.length() > 0)
                    {
                        if (s[0] == c)
                        {
                            s.erase(s.begin());
                            isMatchRec(s, p, found);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                if (s.length() > 0)
                {
                    if (c == '.')
                    {
                        s.erase(s.begin());
                        p.erase(p.begin());
                        isMatchRec(s, p, found);
                    }
                    else
                    {
                        if (c == s[0])
                        {
                            s.erase(s.begin());
                            p.erase(p.begin());
                            isMatchRec(s, p, found);
                        }
                        else
                        {
                            return;
                        }
                    }
                }
                else
                {
                    return;
                }
            }
        }
        else
        {
            if (s.length() > 0)
            {
                if (c == '.')
                {
                    s.erase(s.begin());
                    p.erase(p.begin());
                    isMatchRec(s, p, found);
                }
                else
                {
                    if (c == s[0])
                    {
                        s.erase(s.begin());
                        p.erase(p.begin());
                        isMatchRec(s, p, found);
                    }
                    else
                    {
                        return;
                    }
                }
            }
            else
            {
                return;
            }
        }
    }
};

#endif /* RegularExpressionMatching_h */
