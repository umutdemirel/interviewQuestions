//
//  UniquePaths.h
//  
//
//  https://leetcode.com/problems/unique-paths/description/
//

#ifndef UniquePaths_h
#define UniquePaths_h

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> visited (n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            visited[n-1][i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            visited[i][m-1] = 1;
        }
        
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                visited[i][j] = visited[i][j+1] + visited[i+1][j];
            }
        }
        
        return visited[0][0];
    }
};

#endif /* UniquePaths_h */
