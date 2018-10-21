//
//  MinimumPathSum.h
//  
//
//  https://leetcode.com/problems/minimum-path-sum/description/
//

#ifndef MinimumPathSum_h
#define MinimumPathSum_h

class Solution {
public:
    void minPathRec(vector<vector<int>> &grid, vector<vector<int>> &intMaxGrid, int currentX, int currentY, int &minTotal, int currentTotal)
    {
        if (intMaxGrid[currentY][currentX] > currentTotal)
        {
            intMaxGrid[currentY][currentX] = currentTotal;
        }
        else
        {
            return;
        }
        if (currentX == grid[0].size() - 1 && currentY == grid.size() - 1)
        {
            if (currentTotal + grid[currentY][currentX] < minTotal)
            {
                minTotal = currentTotal + grid[currentY][currentX];
            }
        }
        if (currentX + 1 < grid[0].size() && currentTotal + grid[currentY][currentX + 1] < minTotal)
        {
            minPathRec(grid, intMaxGrid, currentX + 1, currentY, minTotal, currentTotal + grid[currentY][currentX]);
        }
        if (currentY + 1 < grid.size() && currentTotal + grid[currentY + 1][currentX] < minTotal)
        {
            minPathRec(grid, intMaxGrid, currentX, currentY + 1, minTotal, currentTotal + grid[currentY][currentX]);
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int currentX = 0;
        int currentY = 0;
        
        int minTotal = INT_MAX;
        int currentTotal = 0;
        
        if (grid.size() == 0)
        {
            return 0;
        }
        
        vector<vector<int>> intMaxGrid(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        minPathRec(grid, intMaxGrid, currentX, currentY, minTotal, currentTotal);
        
        return minTotal;
    }
};

#endif /* MinimumPathSum_h */
