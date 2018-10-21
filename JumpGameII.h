//
//  JumpGameII.h
//  
//
//  https://leetcode.com/problems/jump-game-ii/description/
//

#ifndef JumpGameII_h
#define JumpGameII_h

class Solution {
public:
    void jumpRec(vector<int>& nums, int currentIndex, int currentJumpNum, int &minJump, vector<int> &visited)
    {
        
        visited[currentIndex] = currentJumpNum;
        
        if (currentJumpNum == minJump)
        {
            return;
        }
        if (currentIndex == nums.size() - 1)
        {
            if (currentJumpNum < minJump)
            {
                minJump = currentJumpNum;
            }
            return;
        }

        for (int i = nums[currentIndex] - 1; i >= 0; i--)
        {
            if (currentIndex + i + 1 < nums.size())
            {
                if (visited[currentIndex + i + 1] < currentJumpNum + 1)
                {
                    return;
                }
                else
                {
                    jumpRec(nums, currentIndex + i + 1, currentJumpNum + 1, minJump, visited);
                }
            }
        }
    }
    
    int jump(vector<int>& nums) {
        vector <int> visited(nums.size(), INT_MAX);
        int minJump = INT_MAX;
        
        jumpRec(nums, 0, 0, minJump, visited);
        
        return minJump;
    }
};

#endif /* JumpGameII_h */
