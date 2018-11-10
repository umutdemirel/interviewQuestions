//
//  GroupAnagrams.h
//  
//
//  https://leetcode.com/problems/group-anagrams/description/
//

#ifndef GroupAnagrams_h
#define GroupAnagrams_h

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        unordered_map<string, vector<string>> hashMap;
        
        for (string word : strs) {
            vector<int> letters(26, 0);
            for (char c : word) {
                letters[c - 'a']++;
            }
            string mapKey = "";
            for (int i : letters) {
                mapKey += "#" + ((char)i - 48);
            }
            
            if (hashMap.find(mapKey) == hashMap.end()) {
                vector<string> anagramList{word};
                hashMap[mapKey] = anagramList;
            } else {
                hashMap[mapKey].push_back(word);
            }
        }
        
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
};

#endif /* GroupAnagrams_h */
