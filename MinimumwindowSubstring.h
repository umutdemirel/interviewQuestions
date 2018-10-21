//
//  MinimumwindowSubstring.h
//  
//
//  https://leetcode.com/problems/minimum-window-substring/description/
//

#ifndef MinimumwindowSubstring_h
#define MinimumwindowSubstring_h

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashMap;
        for (int i = 0 ; i < t.size(); i++)
        {
            if (hashMap.find(t[i]) == hashMap.end())
            {
                hashMap[t[i]] = 1;
            }
            else
            {
                hashMap[t[i]]++;
            }
        }
        
        int counter = t.size();
        int head = 0;
        int begin = 0;
        int end = 0;
        int minLength = INT_MAX;
        while (end < s.size())
        {
            if (hashMap.find(s[end]) != hashMap.end())
            {
                hashMap[s[end]]--;
                if (hashMap[s[end]] >= 0)
                {
                    //cout << s[end] << " " << counter << endl;
                    counter--;
                }
                
                
                while(counter == 0)
                {
                    //cout << begin << "-" << end << " ";
                    if (end - begin < minLength)
                    {
                        head = begin;
                        minLength = end - begin;
                    }
                    if (hashMap.find(s[begin]) != hashMap.end())
                    {
                        hashMap[s[begin]]++;
                        if (hashMap[s[begin]] > 0)
                        {
                            //cout << "counter changed : " << begin << endl;
                            counter++;
                        }
                    }
                    
                    begin++;
                }
                //cout << endl;
            }
            end++;
        }
        return minLength == INT_MAX ? "" : s.substr(head, minLength+1);
    }
};

#endif /* MinimumwindowSubstring_h */
