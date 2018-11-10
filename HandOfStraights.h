//
//  HandOfStraights.h
//  
//
//  https://leetcode.com/problems/hand-of-straights/description/
//

#ifndef HandOfStraights_h
#define HandOfStraights_h

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        sort(hand.begin(), hand.end());
        
        int lastVal;
        int handSize = hand.size();
        int count = 0;
        for (int i = handSize - 1; i >= 0; i--) {
            if (i == handSize - 1) {
                lastVal = hand[i];
                hand.erase(hand.begin() + i);
                count++;
                if (count == W) {
                    if (hand.size() == 0) {
                        return true;
                    }
                    i = hand.size();
                    handSize = hand.size();
                    count = 0;
                }
            } else {
                if (hand[i] == lastVal) {
                    continue;
                } else if (hand[i] == lastVal - 1) {
                    count++;
                    lastVal = hand[i];
                    hand.erase(hand.begin() + i);
                    if (count == W) {
                        if (hand.size() == 0) {
                            return true;
                        }
                        i = hand.size();
                        handSize = hand.size();
                        count = 0;
                    }
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};

#endif /* HandOfStraights_h */
