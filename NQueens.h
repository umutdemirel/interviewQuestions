//
//  NQueens.h
//  
//
//  https://leetcode.com/problems/n-queens/description/
//

#ifndef NQueens_h
#define NQueens_h

class Solution {
public:
    void print(vector<string> map)
    {
        for (int i = 0; i < map.size(); i++)
        {
            cout << map[i] << endl;
        }
    }
    
    void recNQueens(vector<vector<string>> &result, vector<string> map, int n, int currentRow)
    {
        bool queenSet = false;
        for (int i = 0; i < n; i++)
        {
            if (map[currentRow][i] == 'X')
            {
                vector<string> newMap{map};
                
                newMap[currentRow][i] = 'Q';
                queenSet = true;
                
                if (currentRow == n - 1)
                {
                    result.push_back(newMap);
                    continue;
                }
                
                for(int k = 0; k < n; k++)
                {
                    if (newMap[currentRow][k] == 'X')
                    {
                        newMap[currentRow][k] = '.';
                    }
                }
                for(int k = 0; k < n; k++)
                {
                    if (newMap[k][i] == 'X')
                    {
                        newMap[k][i] = '.';
                    }
                }
                int k = 0;
                while(currentRow + k < n && i + k < n)
                {
                    if (newMap[currentRow + k][i + k] == 'X')
                    {
                        newMap[currentRow + k][i + k] = '.';
                    }
                    k++;
                }
                k = 0;
                while(currentRow + k < n && i - k >= 0)
                {
                    if (newMap[currentRow + k][i - k] == 'X')
                    {
                        newMap[currentRow + k][i - k] = '.';
                    }
                    k++;
                }
                k = 0;
                while(currentRow - k >= 0 && i - k >= 0)
                {
                    if (newMap[currentRow - k][i - k] == 'X')
                    {
                        newMap[currentRow - k][i - k] = '.';
                    }
                    k++;
                }
                k = 0;
                while(currentRow - k >= 0 && i + k < n)
                {
                    if (newMap[currentRow - k][i + k] == 'X')
                    {
                        newMap[currentRow - k][i + k] = '.';
                    }
                    k++;
                }
                
                //print(newMap);
                //cout << endl;
                
                recNQueens(result, newMap, n, currentRow + 1);
            }
        }
        if (queenSet == false)
        {
            return;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            temp += 'X';
        }
        vector<string> map;
        for (int i = 0; i < n; i++)
        {
            map.push_back(temp);
        }
        
        vector<vector<string>> result;
        
        recNQueens(result, map, n, 0);
        
        return result;
    }
};

#endif /* NQueens_h */
