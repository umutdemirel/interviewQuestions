//
//  ValidSudoku.h
//  
//
//  https://leetcode.com/problems/valid-sudoku/description/
//

#ifndef ValidSudoku_h
#define ValidSudoku_h

class Solution {
public:
    bool checkVec(vector<char>& board)
    {
        vector <bool> dic(9, false);
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i] != '.')
            {
                if (dic[(int)board[i] - 48 - 1] == false)
                {
                    dic[(int)board[i] - 48 - 1] = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        for (int i = 0; i < board.size(); i++)
        {
            if (checkVec(board[i]) == false)
            {
                return false;
            }
        }
        
        for (int i = 0; i < board.size(); i++)
        {
            vector <char> column;
            for (int j = 0; j < board.size(); j++)
            {
                column.push_back(board[j][i]);
            }
            if (checkVec(column) == false)
            {
                return false;
            }
        }
        
        for (int i = 0; i < board.size(); i++)
        {
            vector <char> cube;
            for (int j = (i/3)*3; j < (i/3)*3 + 3; j++)
            {
                for (int k = (i%3)*3; k < (((i%3)+1)*3); k++)
                {
                    cube.push_back(board[j][k]);
                }
            }
            if (checkVec(cube) == false)
            {
                return false;
            }
        }
        
        return true;
    }
};

#endif /* ValidSudoku_h */
