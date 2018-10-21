//
//  ThreeSum.h
//  
//
//  https://leetcode.com/problems/3sum/description/
//

#ifndef ThreeSum_h
#define ThreeSum_h

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> results;
        
        vector<int> negatives;
        vector<int> positivesDict(200000, -1);
        
        
        
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                //positives.push_back(nums[i]);
                positivesDict[nums[i]] = 1;
            }
            else if (nums[i] < 0)
            {
                negatives.push_back(nums[i]);
                //negativesDict[nums[i] * -1] = 1;
            }
            else if (nums[i] == 0)
            {
                negatives.push_back(nums[i]);
                //negativesDict[nums[i] * -1] = 1;
                zeros++;
                if (zeros == 3)
                {
                    vector <int> result;
                    result.push_back(0);
                    result.push_back(0);
                    result.push_back(0);
                    results.push_back(result);
                }
            }
        }
        sort(negatives.begin(), negatives.end());

        int previous = 1;
        int previous2 = 1;
        int previousP = -1;
        for (int i = 0; i < negatives.size(); i++)
        {
            if (negatives[i] != previous)
            {
                previous2 = 1;
                for (int j = i+1; j < negatives.size(); j++)
                {
                    if (negatives[j] != previous2)
                    {
                        int total = negatives[i] + negatives[j];
                        if (positivesDict[-1 * total] == 1)
                        {
                            vector <int> result;
                            result.push_back(negatives[i]);
                            result.push_back(negatives[j]);
                            result.push_back(-1 * total);
                            results.push_back(result);
                        }
                        previous2 = negatives[j];
                    }
                }
                previous = negatives[i];
            }
        }
        
        vector<int> positives;
        //vector<int> negativesDict(195001, -1);
        positivesDict.assign(200000, -1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                positives.push_back(nums[i]);
                //positivesDict[nums[i]] = 1;
            }
            else if (nums[i] < 0)
            {
                //negatives.push_back(nums[i]);
                positivesDict[nums[i] * -1] = 1;
            }
            else if (nums[i] == 0)
            {
                //negatives.push_back(nums[i]);
                positivesDict[nums[i] * -1] = 1;
                
            }
        }
        sort(positives.begin(), positives.end());
        
        previous = -1;
        previous2 = -1;
        for (int i = 0; i < positives.size(); i++)
        {
            if (positives[i] != previous)
            {
                previous2 = -1;
                for (int j = i+1; j < positives.size(); j++)
                {
                    if (positives[j] != previous2)
                    {
                        int total = positives[i] + positives[j];
                        
                        if (positivesDict[total] == 1)
                        {
                            vector <int> result;
                            result.push_back(positives[i]);
                            result.push_back(positives[j]);
                            result.push_back(-1 * total);
                            results.push_back(result);
                        }
                        previous2 = positives[j];
                    }
                }
                previous = positives[i];
            }
        }
        
        return results;
    }
};

#endif /* ThreeSum_h */
