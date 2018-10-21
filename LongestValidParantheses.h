//
//  LongestValidParantheses.h
//  
//
//  https://leetcode.com/problems/longest-valid-parentheses/description/
//

#ifndef LongestValidParantheses_h
#define LongestValidParantheses_h

class Solution {
public:
    void print(vector <int> &p)
    {
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    
    int longestValidParentheses(string s) {
        int total = 0;
        
        vector <int> newS;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1)
            {
                if (s[i] == '(')
                {
                    newS.push_back(-1);
                }
                else if (s[i] == ')')
                {
                    newS.push_back(-2);
                }
            }
            else
            {
                if (s[i] == '(' && s[i+1] == ')')
                {
                    newS.push_back(2);
                    i++;
                }
                else
                {
                    if (s[i] == '(')
                    {
                        newS.push_back(-1);
                    }
                    else if (s[i] == ')')
                    {
                        newS.push_back(-2);
                    }
                }
            }
        }
        print(newS);
        
        for (int i = newS.size() - 1; i > 0; i--)
        {
            if (newS[i] > 0 && newS[i-1] > 0)
            {
                newS[i-1] = newS[i] + newS[i-1];
                newS.erase(newS.begin() + i);
            }
        }
        print(newS);
        while(true)
        {
            int size = newS.size();
            for (int i = newS.size() - 1; i > 1; i--)
            {
                if (newS[i] == -2 && newS[i-1] > 0 && newS[i-2] == -1)
                {
                    newS[i-2] = newS[i-1] + 2;
                    newS.erase(newS.begin() + i);
                    newS.erase(newS.begin() + i-1);
                }
            }
            for (int i = newS.size() - 1; i > 0; i--)
            {
                if (newS[i] > 0 && newS[i-1] > 0)
                {
                    newS[i-1] = newS[i] + newS[i-1];
                    newS.erase(newS.begin() + i);
                }
            }
            int newSize = newS.size();
            if (size == newSize)
            {
                break;
            }
        }
        print(newS);
        
        for (int i = 0; i < newS.size(); i++)
        {
            if (newS[i] > total)
            {
                total = newS[i];
            }
        }
        
        return total;
    }
};

#endif /* LongestValidParantheses_h */
