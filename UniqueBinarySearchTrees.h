//
//  UniqueBinarySearchTrees.h
//  
//
//  https://leetcode.com/problems/unique-binary-search-trees/description/
//

#ifndef UniqueBinarySearchTrees_h
#define UniqueBinarySearchTrees_h

class Solution {
public:
    int numTreesRec(int n, unordered_map<int, int> &hashMap)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            int total = 0;
            for (int i = 0; i < n; i++)
            {
                int first;
                int second;
                if (hashMap.find(i) != hashMap.end())
                {
                    first = hashMap[i];
                }
                else
                {
                    first = numTreesRec(i, hashMap);
                }
                if (hashMap.find(n-i-1) != hashMap.end())
                {
                    second = hashMap[n-i-1];
                }
                else
                {
                    second = numTreesRec(n-i-1, hashMap);
                }
                
                total += (first * second);
            }
            hashMap[n] = total;
            return hashMap[n];
        }
    }
    
    int numTrees(int n) {
        unordered_map<int, int> hashMap;
        return numTreesRec(n, hashMap);
    }
};

#endif /* UniqueBinarySearchTrees_h */
