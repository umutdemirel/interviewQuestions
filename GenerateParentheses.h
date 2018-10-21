//
//  GenerateParentheses.h
//  
//
//  https://leetcode.com/problems/generate-parentheses/description/
//

#ifndef GenerateParentheses_h
#define GenerateParentheses_h

class Solution {
public:
    
    void genParRec(int oP, int cP, int totalPairs, int it, string currentStr, vector<string>* results)
    {
        if (it == 0)
        {
            results->push_back(currentStr);
            return;
        }
        if (oP == cP)
        {
            genParRec(oP+1, cP, totalPairs, it - 1, currentStr + '(', results);
        }
        else if (oP > 0 && oP < totalPairs)
        {
            genParRec(oP+1, cP, totalPairs, it - 1, currentStr + '(', results);
            genParRec(oP, cP+1, totalPairs, it - 1, currentStr + ')', results);
        }
        else if (oP > 0 && oP == totalPairs)
        {
            genParRec(oP, cP+1, totalPairs, it - 1, currentStr + ')', results);
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        int numOfOpenParanthesis = 0;
        int numOfCloseParanthesis = 0;
        int numOfIterations = n * 2;
        
        vector<string> results;
        
        genParRec(numOfOpenParanthesis, numOfCloseParanthesis, n, numOfIterations, "", &results);
        
        return results;
    }
};

#endif /* GenerateParentheses_h */
