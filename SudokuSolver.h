//
//  SudokuSolver.h
//  
//
//  https://leetcode.com/problems/sudoku-solver/description/
//

#ifndef SudokuSolver_h
#define SudokuSolver_h

class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char value)
    {
        for (int a = 0; a < board.size(); a++)
        {
            if (a != i && board[a][j] == value)
            {
                return false;
            }
        }
        for (int a = 0; a < board.size(); a++)
        {
            if (a != j && board[i][a] == value)
            {
                return false;
            }
        }
        for (int a = i - i % 3; a < i - i % 3 + 3; a++)
        {
            for (int b = j - j % 3; b < j - j % 3 + 3; b++)
            {
                if (a != i && b != j && board[a][b] == value)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector < pair < pair <int, int>, char > > stack;
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    pair <int, int> coors(i,j);
                    pair < pair <int, int>, int > info;
                    info.first = coors;
                    info.second = '1';
                    stack.push_back(info);
                    
                    board[i][j] = info.second;
                    
                    while (check(board, i, j, stack[stack.size() - 1].second) == false)
                    {
                        while (stack[stack.size() - 1].second + 1 > '9')
                        {
                            board[i][j] = '.';
                            stack.pop_back();
                            i = stack[stack.size() - 1].first.first;
                            j = stack[stack.size() - 1].first.second;
                        }
                        stack[stack.size() - 1].second += 1;
                        board[i][j] = stack[stack.size() - 1].second;
                    }
                }
            }
        }
    }
};

#endif /* SudokuSolver_h */
