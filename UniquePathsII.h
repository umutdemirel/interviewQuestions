//
//  UniquePathsII.h
//  
//
//  https://leetcode.com/problems/unique-paths-ii/description/
//

#ifndef UniquePathsII_h
#define UniquePathsII_h

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
        {
            return 0;
        }
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
        {
            return 0;
        }
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1)
        {
            if (obstacleGrid[0][0] == 0)
            {
                return 1;
            }
            else if (obstacleGrid[0][0] == 1)
            {
                return 0;
            }
        }
        
        vector<vector<int>> dynamicGrid(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        
        bool obstacleFound = false;
        for (int i = dynamicGrid[0].size() - 2; i >= 0; i--)
        {
            if (obstacleFound)
            {
                dynamicGrid[dynamicGrid.size() - 1][i] = 0;
            }
            else
            {
                if (obstacleGrid[dynamicGrid.size() - 1][i] == 1)
                {
                    obstacleFound = true;
                    dynamicGrid[dynamicGrid.size() - 1][i] = 0;
                }
                else
                {
                    dynamicGrid[dynamicGrid.size() - 1][i] = 1;
                }
            }
        }
        
        obstacleFound = false;
        for (int i = dynamicGrid.size() - 2; i >= 0; i--)
        {
            if (obstacleFound)
            {
                dynamicGrid[i][dynamicGrid[0].size() - 1] = 0;
            }
            else
            {
                if (obstacleGrid[i][dynamicGrid[0].size() - 1] == 1)
                {
                    obstacleFound = true;
                    dynamicGrid[i][dynamicGrid[0].size() - 1] = 0;
                }
                else
                {
                    dynamicGrid[i][dynamicGrid[0].size() - 1] = 1;
                }
            }
        }
        
        for (int i = dynamicGrid.size() - 2; i >= 0; i--)
        {
            for (int j = dynamicGrid[0].size() - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dynamicGrid[i][j] = 0;
                }
                else
                {
                    dynamicGrid[i][j] = dynamicGrid[i+1][j] + dynamicGrid[i][j+1];
                }
            }
        }
        
        return dynamicGrid[0][0];
    }
};

#endif /* UniquePathsII_h */
