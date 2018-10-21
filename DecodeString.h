//
//  DecodeString.h
//  
//
//  https://leetcode.com/problems/decode-string/
//

#ifndef DecodeString_h
#define DecodeString_h

class Solution {
public:
    int strToInt(string str) {
        int number = 0;
        int mult = 1;
        for (int i = str.size() - 1; i >= 0; i--) {
            number += ((str[i] - '0') * mult);
            mult *= 10;
        }
        return number;
    }
    
    string getString(string s) {
        string result = "";
        string number = "";
        string strGroup = "";
        int numOfP = 0;
        bool isStrGroupStarted = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                if (isStrGroupStarted) {
                    strGroup += s[i];
                } else {
                    number += s[i];
                }
            } else if ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a')) {
                if (!isStrGroupStarted) {
                    // add to result
                    result += s[i];
                } else {
                    // add strGroup
                    strGroup += s[i];
                }
            } else if (s[i] == '[') {
                if (!isStrGroupStarted) {
                    // finish number & start strGroup
                    isStrGroupStarted = true;
                    numOfP++;
                } else {
                    strGroup += s[i];
                    numOfP++;
                }
            } else if (s[i] == ']') {
                // numOf[-- && finish strGroup if numOf[ == 0
                numOfP--;
                if (numOfP == 0) {
                    // convert number string to int
                    int num = strToInt(number);
                    for (int i = 0; i < num; i++) {
                        result += getString(strGroup);
                    }
                    strGroup = "";
                    number = "";
                    isStrGroupStarted = false;
                } else {
                    strGroup += s[i];
                }
            }
        }
        
        return result;
    }
    
    string decodeString(string s) {
        string result = getString(s);
        
        return result;
    }
};

#endif /* DecodeString_h */
