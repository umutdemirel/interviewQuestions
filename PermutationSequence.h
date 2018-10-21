//
//  PermutationSequence.h
//  
//
//  https://leetcode.com/problems/permutation-sequence/description/
//

#ifndef PermutationSequence_h
#define PermutationSequence_h

class Solution {
public:
    
    string getPermutation(int n, int k) {
        string nums = "";
        for (int i = 1; i < n+1; i++)
        {
            nums += ('0' + i);
        }
        
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
        
        string result = "";
        while (k > 1)
        {
            //cout << "before : " << k << " " << fact << " " << n << endl;
            int num = (k-1) / (fact / n);
            //cout << num << endl;
            
            result += nums[num];
            
            nums.erase(nums.begin() + num);
            
            cout << nums << endl;
            
            k = k - (num * (fact / n));
            fact = fact / n;
            n--;
            
            //cout << "after : " << k << " " << fact << " " << n << endl;
        }
        
        result += nums;
        
        return result;
    }
};

#endif /* PermutationSequence_h */
