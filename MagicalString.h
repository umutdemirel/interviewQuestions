//
//  MagicalString.h
//
//
//  https://leetcode.com/problems/magical-string/description/
//

#ifndef MagicalString_h
#define MagicalString_h

class Solution {
public:
    int magicalString(int n) {
        string upMagic = "";
        string downMagic = "1";
        
        int count = 0;
        
        bool adding1 = true;
        int iterator = 0;
        while (true) {
            if (iterator < upMagic.size()) {
                downMagic += upMagic[iterator];
            } else if (iterator == downMagic.size()) {
                if (adding1) {
                    downMagic += '1';
                } else {
                    downMagic += '2';
                }
            }
            
            if (downMagic[iterator] == '1') {
                if (adding1) {
                    upMagic += '1';
                    count += 1;
                } else {
                    upMagic += '2';
                }
                adding1 = !adding1;
                iterator++;
            } else {
                if (adding1) {
                    upMagic += "11";
                    count += 2;
                } else {
                    upMagic += "22";
                }
                adding1 = !adding1;
                iterator++;
            }
            
            if (upMagic.size() == n) {
                return count;
            } else if (upMagic.size() == n + 1) {
                return upMagic.back() == '1' ? count - 1 : count;
            }
        }
    }
};

#endif /* MagicalString_h */
