//
//  SimplifyPath.h
//  
//
//  https://leetcode.com/problems/simplify-path/description/
//

#ifndef SimplifyPath_h
#define SimplifyPath_h

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        
        string tempPath = "";
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (tempPath != "")
                {
                    if (tempPath == "..")
                    {
                        if (stack.size() > 0)
                        {
                            stack.pop_back();
                        }
                    }
                    else if (tempPath == ".")
                    {
                        
                    }
                    else
                    {
                        stack.push_back(tempPath);
                    }
                    tempPath = "";
                }
            }
            else
            {
                tempPath += path[i];
            }
        }
        if (tempPath != "")
        {
            if (tempPath == "..")
            {
                if (stack.size() > 0)
                {
                    stack.pop_back();
                }
            }
            else if (tempPath == ".")
            {
                
            }
            else
            {
                stack.push_back(tempPath);
            }
        }
        
        if (stack.size() == 0)
        {
            return "/";
        }
        else
        {
            string resultStr = "/";
            for (int i = 0; i < stack.size(); i++)
            {
                if (i < stack.size() - 1)
                {
                    resultStr += stack[i] + "/";
                }
                else
                {
                    resultStr += stack[i];
                }
            }
            return resultStr;
        }
    }
};

#endif /* SimplifyPath_h */
