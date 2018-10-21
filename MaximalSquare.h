//
//  MaximalSquare.h
//  
//
//  https://leetcode.com/problems/maximal-square/description/
//

#ifndef MaximalSquare_h
#define MaximalSquare_h

class Solution {
public:
    void checkSquare(vector<vector<char>>& matrix, int row, int column, int& tempSide) {
        if (row + 1 < matrix.size() && column + 1 < matrix[row].size() && matrix[row + 1][column + 1] == '1') {
            for (int i = row + 1; i >= row + 1 - tempSide; i--) {
                if (matrix[i][column + 1] != '1') {
                    return;
                }
            }
            for (int i = column + 1; i >= column + 1 - tempSide; i--) {
                if (matrix[row + 1][i] != '1') {
                    return;
                }
            }
            tempSide++;
            checkSquare(matrix, row + 1, column + 1, tempSide);
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSide = 0;
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                if (matrix[row][column] == '1') {
                    int tempSide = 1;
                    checkSquare(matrix, row, column, tempSide);
                    maxSide = max(maxSide, tempSide);
                }
            }
        }
        
        return maxSide * maxSide;
    }
};

#endif /* MaximalSquare_h */
