//
//  NQueensII.h
//  
//
//  https://leetcode.com/problems/n-queens-ii/description/
//

#ifndef NQueensII_h
#define NQueensII_h

class Solution {
public:
    void print(vector<string> map)
    {
        for (int i = 0; i < map.size(); i++)
        {
            cout << map[i] << endl;
        }
    }
    
    void recNQueens(int &result, vector<string> map, int n, int currentRow, int middle)
    {
        bool queenSet = false;
        int index = currentRow == 0 ? n / 2 : n;
        int startingPoint = middle ? n / 2 : 0;
        index = middle ? n / 2 + 1 : index;
        for (int i = startingPoint; i < index; i++)
        {
            if (map[currentRow][i] == 'X')
            {
                vector<string> newMap{map};
                
                newMap[currentRow][i] = 'Q';
                queenSet = true;
                
                if (currentRow == n - 1)
                {
                    result++;
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
                
                recNQueens(result, newMap, n, currentRow + 1, false);
            }
        }
        if (queenSet == false)
        {
            return;
        }
    }
    
    int totalNQueens(int n) {
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
        
        int result = 0;
        
        if (n == 1 || n == 0)
        {
            return 1;
        }
        else if (n < 4)
        {
            return 0;
        }
        
        recNQueens(result, map, n, 0, false);
        
        result *= 2;
        if (n % 2 == 1)
        {
            recNQueens(result, map, n, 0, true);
        }
        
        return result;
    }
};

#endif /* NQueensII_h */
