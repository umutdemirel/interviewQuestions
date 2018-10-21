//
//  RotateImage.h
//  
//
//  https://leetcode.com/problems/rotate-image/description/
//

#ifndef RotateImage_h
#define RotateImage_h

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++)
        {
            int rotationTimes = matrix.size() - i * 2 - 1;
            for (int k = 0; k < rotationTimes; k++)
            {
                for (int j = 0; j < rotationTimes; j++)
                {
                    //cout << rotationTimes << " " << matrix[j + i][i] << " " << matrix[j+i+1][i] << endl;
                    swap(matrix[j + i][i], matrix[j + i + 1][i]);
                }
                for (int j = 0; j < rotationTimes; j++)
                {
                    //cout << matrix[matrix.size() - 1 - i][j+i] << " " << matrix[matrix.size() - 1 - i][j+i+1] << endl;
                    swap(matrix[matrix.size() - 1 - i][j+i], matrix[matrix.size() - 1 - i][j+i+1]);
                }
                for (int j = 0; j < rotationTimes; j++)
                {
                    //cout << matrix[matrix.size() - 1 - i - j][matrix.size() - 1 - i] << " " << matrix[matrix.size() - 1 - i - j - 1][matrix.size() - 1 - i] << endl;
                    swap(matrix[matrix.size() - 1 - i - j][matrix.size() - 1 - i],
                         matrix[matrix.size() - 1 - i - j - 1][matrix.size() - 1 - i]);
                }
                for (int j = 0; j < rotationTimes - 1; j++)
                {
                    //cout << matrix[i][matrix.size() - 1 - i - j] << " " << matrix[i][matrix.size() - 1 - i - j - 1] << endl;
                    swap(matrix[i][matrix.size() - 1 - i - j], matrix[i][matrix.size() - 1 - i - j - 1]);
                }
            }
            
        }
    }
};

#endif /* RotateImage_h */
