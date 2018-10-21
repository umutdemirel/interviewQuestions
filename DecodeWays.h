//
//  DecodeWays.h
//  
//
//  https://leetcode.com/problems/decode-ways/description/
//

#ifndef DecodeWays_h
#define DecodeWays_h

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 2, 0);
        dp[dp.size() - 2] = 1;
        dp[dp.size() - 1] = 0;
        
        bool zeroDetected = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                if (i > 0) {
                    if (s[i - 1] == '1' || s[i - 1] == '2') {
                        dp[i] = dp[i + 1];
                        dp[i - 1] = dp[i];
                        i--;
                        zeroDetected = true;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else if (zeroDetected) {
                dp[i] = dp[i + 1];
                zeroDetected = false;
            } else if ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1') {
                dp[i] = dp[i + 1] + dp[i + 2];
            } else {
                dp[i] = dp[i + 1];
            }
        }
        /*
         for (int i = 0; i < dp.size(); i++) {
         cout << dp[i] << " ";
         }
         cout << endl;
         */
        return dp[0];
    }
};

#endif /* DecodeWays_h */
