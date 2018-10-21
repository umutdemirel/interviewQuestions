//
//  QueueReconstructionByHeight.h
//  
//
//  https://leetcode.com/problems/queue-reconstruction-by-height/description/
//

#ifndef QueueReconstructionByHeight_h
#define QueueReconstructionByHeight_h

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        map<int, vector<int>> hashMap;
        
        vector<pair<int, int>> result(people.size(), pair<int, int>(-1, -1));
        
        for (auto person : people) {
            hashMap[person.first].push_back(person.second);
        }
        
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            vector<int> tempNumbers = it->second;
            sort(tempNumbers.begin(), tempNumbers.end());
            for (int number : tempNumbers) {
                int count = 0;
                for (int i = 0; i < result.size(); i++) {
                    if (result[i].first == -1) {
                        if (count == number) {
                            result[i] = make_pair(it->first, number);
                            break;
                        } else {
                            count++;
                        }
                    } else if (result[i].first >= it->first) {
                        count++;
                    }
                }
            }
        }
        
        return result;
    }
};

#endif /* QueueReconstructionByHeight_h */
