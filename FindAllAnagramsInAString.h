//
//  FindAllAnagramsInAString.h
//  
//
//  https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
//

#ifndef FindAllAnagramsInAString_h
#define FindAllAnagramsInAString_h

class Solution {
public:
    bool checkHashMap(unordered_map<char, int> hashMap) {
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            if (it->second > 0) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> startingPoints;
        
        unordered_map<char, int> hashMap;
        for (int i = 0; i < p.size(); i++) {
            if (hashMap.find(p[i]) != hashMap.end()) {
                hashMap[p[i]]++;
            } else {
                hashMap[p[i]] = 1;
            }
        }
        
        int startIndex = 0;
        int endIndex = 0;
        
        for (; endIndex < s.size(); endIndex++) {
            if (hashMap.find(s[endIndex]) != hashMap.end()) {
                if (hashMap[s[endIndex]] > 0) {
                    hashMap[s[endIndex]]--;
                } else {
                    // move start by 1
                    while(hashMap[s[endIndex]] == 0) {
                        hashMap[s[startIndex]]++;
                        startIndex++;
                    }
                    hashMap[s[endIndex]]--;
                }
                if (endIndex - startIndex + 1 == p.size()) {
                    if (checkHashMap(hashMap)) {
                        startingPoints.push_back(startIndex);
                    }
                    hashMap[s[startIndex]]++;
                    startIndex++;
                }
            } else {
                // bring start and and to i+1
                while(startIndex < endIndex) {
                    hashMap[s[startIndex]]++;
                    startIndex++;
                }
                startIndex++;
            }
        }
        
        return startingPoints;
    }
};

#endif /* FindAllAnagramsInAString_h */
