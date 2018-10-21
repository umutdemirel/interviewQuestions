//
//  SearchA2DMatrixII.h
//  
//
//  https://leetcode.com/problems/search-a-2d-matrix-ii/description/
//

#ifndef SearchA2DMatrixII_h
#define SearchA2DMatrixII_h

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int columnLimit = matrix[0].size() - 1;
        int rowLimit = matrix.size() - 1;
        for (int row = 0; row < rowLimit + 1; row++) {
            if (matrix[row][0] > target) {
                break;
            }
            for (int column = 0; column < columnLimit + 1; column++) {
                if (matrix[row][column] == target) {
                    return true;
                } else if (matrix[row][column] > target) {
                    columnLimit = column;
                    break;
                }
            }
        }
        
        return false;
    }
};

#endif /* SearchA2DMatrixII_h */
