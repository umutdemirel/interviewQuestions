//
//  SpiralMatrix.h
//  
//
//  https://leetcode.com/problems/spiral-matrix/description/
//

#ifndef SpiralMatrix_h
#define SpiralMatrix_h

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int horizontalIterator = 0;
        int verticalIterator = 0;
        
        vector<int> result;
        
        int verticalLength = matrix.size();
        int horizontalLength;
        
        if (verticalLength > 0)
        {
            horizontalLength = matrix[0].size();
        }
        else
        {
            return result;
        }
        
        if (verticalLength == 1)
        {
            return matrix[0];
        }
        if (horizontalLength == 1)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                result.push_back(matrix[i][0]);
            }
            return result;
        }
        
        int shell = 0;
        while(shell < (min(verticalLength, horizontalLength) + 1) / 2)
        {
            horizontalIterator = shell;
            verticalIterator = shell;
            if (horizontalIterator == horizontalLength - shell - 1)
            {
                for (int i = horizontalIterator; i < verticalLength - verticalIterator; i++)
                {
                    result.push_back(matrix[i][horizontalIterator]);
                }
                break;
            }
            for (horizontalIterator = shell; horizontalIterator < horizontalLength - shell - 1; horizontalIterator++)
            {
                result.push_back(matrix[verticalIterator][horizontalIterator]);
            }
            
            if (verticalIterator == verticalLength - shell - 1)
            {
                result.push_back(matrix[verticalIterator][horizontalIterator]);
                break;
            }
            for (verticalIterator = shell;
                 verticalIterator < verticalLength - shell - 1;
                 verticalIterator++)
            {
                result.push_back(matrix[verticalIterator][horizontalIterator]);
            }
            
            for (horizontalIterator = horizontalLength - shell - 1; horizontalIterator > shell; horizontalIterator--)
            {
                result.push_back(matrix[verticalIterator][horizontalIterator]);
            }
            
            for (verticalIterator = verticalLength - 1 - shell;
                 verticalIterator > shell;
                 verticalIterator--)
            {
                result.push_back(matrix[verticalIterator][horizontalIterator]);
            }
            shell++;
        }
        
        return result;
    }
};

#endif /* SpiralMatrix_h */
