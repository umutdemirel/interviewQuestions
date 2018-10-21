//
//  CountAndSay.h
//  
//
//  https://leetcode.com/problems/count-and-say/description/
//

#ifndef CountAndSay_h
#define CountAndSay_h

#include <stdlib>

class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for (int i = 1; i < n; i++)
        {
            int count = 0;
            char currentChar;
            string newCurrent = "";
            for (int j = 0 ; j < current.length(); j++)
            {
                if (count == 0)
                {
                    count++;
                    currentChar = current[j];
                }
                else
                {
                    if (currentChar == current[j])
                    {
                        count++;
                    }
                    else
                    {
                        //cout << "came1 " << count << " " << currentChar << endl;
                        newCurrent += to_string(count) + currentChar;
                        currentChar = current[j];
                        count = 1;
                    }
                }
            }
            if (count > 0)
            {
                //cout << "came2 " << count << " " << currentChar << endl;
                newCurrent += to_string(count) + currentChar;
            }
            current = newCurrent;
        }
        return current;
    }
};

#endif /* CountAndSay_h */
