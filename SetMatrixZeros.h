//
//  SetMatrixZeros.h
//  
//
//  https://leetcode.com/problems/set-matrix-zeroes/description/
//

#ifndef SetMatrixZeros_h
#define SetMatrixZeros_h

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(), false);
        vector<bool> columns(matrix[0].size(), false);
        
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                if (matrix[row][column] == 0) {
                    rows[row] = true;
                    columns[column] = true;
                }
            }
        }
        
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                if (rows[row] || columns[column]) {
                    matrix[row][column] = 0;
                }
            }
        }
    }
};

#endif /* SetMatrixZeros_h */
