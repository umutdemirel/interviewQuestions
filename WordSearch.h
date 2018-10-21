//
//  WordSearch.h
//  
//
//  https://leetcode.com/problems/word-search/description/
//

#ifndef WordSearch_h
#define WordSearch_h

class Solution {
public:
    void checkBoard(vector<vector<bool>> visited, vector<vector<char>> &board, string word, bool &found, int row, int column)
    {
        if (found)
        {
            return;
        }
        if (visited[row][column] == false && board[row][column] == word[0])
        {
            if (word.size() == 1)
            {
                found = true;
                return;
            }
            else
            {
                vector<vector<bool>> visitedNew{visited};
                visitedNew[row][column] = true;
                
                word.erase(word.begin());
                
                if (row + 1 < board.size() && visitedNew[row+1][column] == false)
                {
                    checkBoard(visitedNew, board, word, found, row+1, column);
                }
                if (row - 1 >= 0 && visitedNew[row-1][column] == false)
                {
                    checkBoard(visitedNew, board, word, found, row-1, column);
                }
                if (column + 1 < board[0].size() && visitedNew[row][column+1] == false)
                {
                    checkBoard(visitedNew, board, word, found, row, column+1);
                }
                if (column - 1 >= 0 && visitedNew[row][column-1] == false)
                {
                    checkBoard(visitedNew, board, word, found, row, column-1);
                }
            }
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        bool found = false;
        for (int row = 0; row < board.size(); row++)
        {
            for (int column = 0; column < board[0].size(); column++)
            {
                if (board[row][column] == word[0])
                {
                    if (word.size() == 1)
                    {
                        return true;
                    }
                    else
                    {
                        checkBoard(visited, board, word, found, row, column);
                    }
                }
            }
        }
        
        return found;
    }
};

#endif /* WordSearch_h */
