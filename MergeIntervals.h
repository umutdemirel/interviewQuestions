//
//  MergeIntervals.h
//  
//
//  https://leetcode.com/problems/merge-intervals/description/
//

#ifndef MergeIntervals_h
#define MergeIntervals_h

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector <int> visited(7000, -1);
        int middle = visited.size() / 2;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            
            for (int j = intervals[i].start; j <= intervals[i].end; j++)
            {
                if (visited[middle + j] == -1)
                {
                    visited[middle + j] = i;
                }
                else
                {
                    int tempValue = visited[middle + j];
                    visited[middle + j] = i;
                    
                    if (j == intervals[i].start)
                    {
                        for (int k = middle + j - 1; k >= 0; k--)
                        {
                            if (visited[k] == tempValue)
                            {
                                visited[k] = i;
                            }
                        }
                    }
                    if (j == intervals[i].end)
                    {
                        for (int k = middle + j + 1; k < visited.size() - 1; k++)
                        {
                            if (visited[k] == tempValue)
                            {
                                visited[k] = i;
                            }
                        }
                    }
                    else
                    {
                        visited[middle + j] = i;
                    }
                }
            }
            /*
             for (int j = middle ; j < middle + 10; j++)
             {
             cout << visited[j] << " ";
             }
             cout << endl;
             */
        }
        
        vector<Interval> result;
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] > -1)
            {
                int foundId = visited[i];
                Interval tempInterval;
                tempInterval.start = i - middle;
                int j;
                for (j = i+1; j < visited.size(); j++)
                {
                    if (visited[j] != foundId)
                    {
                        break;
                    }
                }
                if (j == visited.size())
                {
                    tempInterval.end = visited.size() - middle;
                }
                else
                {
                    tempInterval.end = j - 1 - middle;
                }
                result.push_back(tempInterval);
                i = j - 1;
            }
        }
        return result;
    }
};

#endif /* MergeIntervals_h */
