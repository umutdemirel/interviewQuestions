//
//  SubstringWithConcatenationOfAllWords.h
//  
//
//  https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
//

#ifndef SubstringWithConcatenationOfAllWords_h
#define SubstringWithConcatenationOfAllWords_h

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        
        int totalWordLengths = 0;
        int wordSize = -1;
        for (int i = 0; i < words.size(); i++)
        {
            if (i == 0)
            {
                wordSize = words[i].length();
            }
            else
            {
                if (words[i].length() != wordSize)
                {
                    return results;
                }
            }
            totalWordLengths += words[i].length();
        }
        
        if (s.length() < totalWordLengths)
        {
            return results;
        }
        
        if (words.size() == 0)
        {
            return results;
        }
        
        for (int i = 0; i < s.length() - totalWordLengths + 1; i++)
        {
            string tempS = s.substr(i, totalWordLengths);
            vector <bool> checked(words.size(), false);
            
            for (int k = 0; k < words.size(); k++)
            {
                bool found2 = false;
                for (int j = 0; j < words.size(); j++)
                {
                    if (checked[j] == false)
                    {
                        string str = words[j];
                        //cout << j << " comparing : " << tempS.substr(0, str.length()) << " with " << str << endl;
                        if (tempS.substr(0, str.length()) == str)
                        {
                            checked[j] = true;
                            found2 = true;
                            tempS = tempS.substr(str.length(), tempS.length() - str.length());
                            break;
                        }
                    }
                }
                if (found2 == false)
                {
                    break;
                }
            }
            
            bool found = true;
            for (int k = 0; k < checked.size(); k++)
            {
                if (checked[k] == false)
                {
                    found = false;
                    break;
                }
            }
            
            if (found == true)
            {
                //cout << "pushing : " << i << endl;
                results.push_back(i);
            }
        }
        
        return results;
    }
};

#endif /* SubstringWithConcatenationOfAllWords_h */
