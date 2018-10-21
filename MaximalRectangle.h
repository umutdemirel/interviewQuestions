//
//  MaximalRectangle.h
//  
//
//  https://leetcode.com/problems/maximal-rectangle/description/
//

#ifndef MaximalRectangle_h
#define MaximalRectangle_h

class Solution {
public:
    int calculateMax(vector<int> lengthList) {
        //cout << "list size : " << lengthList.size() << endl;
        int max = lengthList.size();
        for (int i = 0; i < lengthList.size(); i++) {
            int currentMax = lengthList[i];
            //cout << currentMax << " ";
            for (int j = i+1; j < lengthList.size(); j++) {
                if (lengthList[j] >= lengthList[i]) {
                    currentMax += lengthList[i];
                }
                else {
                    break;
                }
            }
            for (int j = i-1; j >= 0; j--) {
                if (lengthList[j] >= lengthList[i]) {
                    currentMax += lengthList[i];
                }
                else {
                    break;
                }
            }
            //cout << currentMax << " max : " << max;
            if (currentMax > max) {
                max = currentMax;
            }
            //cout << ", new max : " << max << endl;
        }
        //cout << endl;
        return max;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        
        int maxRect = 0;
        /*
         for (int row = 0; row < matrix.size(); row++) {
         for (int column = 0; column < matrix[0].size(); column++) {
         cout << matrix[row][column] << " ";
         }
         cout << endl;
         }
         */
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[0].size(); column++) {
                if (matrix[row][column] == '1')
                {
                    int tempRow = row;
                    vector<int> lengthList;
                    while(tempRow < matrix.size() && matrix[tempRow][column] == '1') {
                        int tempColumn = column;
                        int currentLength = 0;
                        while(tempColumn < matrix[0].size() && matrix[tempRow][tempColumn] == '1') {
                            currentLength++;
                            tempColumn++;
                        }
                        lengthList.push_back(currentLength);
                        tempRow++;
                    }
                    int tempMax = calculateMax(lengthList);
                    if (tempMax > maxRect) {
                        maxRect = tempMax;
                    }
                }
            }
        }
        
        return maxRect;
    }
};

#endif /* MaximalRectangle_h */
