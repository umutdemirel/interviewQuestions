//
//  SpiralMatrixII.h
//  
//
//  https://leetcode.com/problems/spiral-matrix-ii/description/
//

#ifndef SpiralMatrixII_h
#define SpiralMatrixII_h

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, -1));
        
        int value = 1;
        
        int horizontal = 1;
        int vertical = 0;
        
        int horIndex = 0;
        int verIndex = 0;
        
        int movingDirection = 0;
        
        while(true)
        {
            result[verIndex][horIndex] = value;
            value++;
            
            if (movingDirection == 0 && (horIndex == n - 1 || result[verIndex][horIndex + 1] > -1))
            {
                movingDirection = 1;
                horizontal = 0;
                vertical = 1;
            }
            else if (movingDirection == 1 && (verIndex == n - 1 || result[verIndex + 1][horIndex] > -1))
            {
                movingDirection = 2;
                horizontal = -1;
                vertical = 0;
            }
            else if (movingDirection == 2 && (horIndex == 0 || result[verIndex][horIndex - 1] > -1))
            {
                movingDirection = 3;
                horizontal = 0;
                vertical = -1;
            }
            else if (movingDirection == 3 && (verIndex == 0 || result[verIndex - 1][horIndex] > -1))
            {
                movingDirection = 0;
                horizontal = 1;
                vertical = 0;
            }
            
            horIndex += horizontal;
            verIndex += vertical;
            
            //cout << horIndex << " " << verIndex << endl;
            
            if (horIndex > n - 1 || horIndex < 0 || verIndex > n - 1 || verIndex < 0 || result[verIndex][horIndex] > -1)
            {
                //cout << horIndex << " " << verIndex << " " << result[verIndex][horIndex] << endl;
                break;
            }
        }
        
        
        
        return result;
    }
};

#endif /* SpiralMatrixII_h */
