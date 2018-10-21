//
//  NumberOfIslands.h
//  
//
//  https://leetcode.com/problems/number-of-islands/description/
//

#ifndef NumberOfIslands_h
#define NumberOfIslands_h

class Solution {
public:
    void setIslandRec(vector<vector<char>>& grid, int i, int j)
    {
        if (i > 0 && grid[i-1][j] == '1')
        {
            grid[i-1][j] = '2';
            setIslandRec(grid, i-1, j);
        }
        if (i < grid.size() - 1 && grid[i+1][j] == '1')
        {
            grid[i+1][j] = '2';
            setIslandRec(grid, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == '1')
        {
            grid[i][j-1] = '2';
            setIslandRec(grid, i, j-1);
        }
        if (j < grid[0].size() - 1 && grid[i][j+1] == '1')
        {
            grid[i][j+1] = '2';
            setIslandRec(grid, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int totalIslands = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    totalIslands++;
                    grid[i][j] = '2';
                    setIslandRec(grid, i, j);
                }
            }
        }
        
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        
        
        return totalIslands;
    }
};

#endif /* NumberOfIslands_h */
