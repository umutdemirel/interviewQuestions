//
//  JumpGame.h
//  
//
//  https://leetcode.com/problems/jump-game/description/
//

#ifndef JumpGame_h
#define JumpGame_h


// t t t t f f
// 3 3 1 0 1 5

class Solution {
public:
    void canJumpRec(vector<int>& nums, vector <bool> &visited, int currentIndex, bool &found)
    {
        if (found == true)
        {
            return;
        }
        if (nums.size() - 1 - currentIndex <= nums[currentIndex])
        {
            found = true;
            return;
        }
        visited[currentIndex] = true;
        for (int i = nums[currentIndex]; i >= 1 ; i--)
        {
            if (visited[currentIndex + i] == false)
            {
                canJumpRec(nums, visited, currentIndex + i, found);
            }
        }
    }
    
    bool canJump(vector<int>& nums) {
        vector <bool> visited(nums.size(), false);
        bool found = false;
        int currentIndex = 0;
        canJumpRec(nums, visited, currentIndex, found);
        return found;
    }
};

#endif /* JumpGame_h */
