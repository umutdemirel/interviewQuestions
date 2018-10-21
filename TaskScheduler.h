//
//  TaskScheduler.h
//  
//
//  https://leetcode.com/problems/task-scheduler/description/
//

#ifndef TaskScheduler_h
#define TaskScheduler_h

class Solution {
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.second > b.second);
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        vector < pair < char, int> > taskList;
        
        for (int i = 0; i < tasks.size(); i++) {
            bool found = false;
            for (int j = 0; j < taskList.size(); j++) {
                if (taskList[j].first == tasks[i]) {
                    taskList[j].second++;
                    int tempJ = j;
                    while(tempJ > 0 && taskList[tempJ].second > taskList[tempJ - 1].second) {
                        pair <char, int> tempPair = taskList[tempJ];
                        taskList[tempJ] = taskList[tempJ - 1];
                        taskList[tempJ - 1] = tempPair;
                        tempJ--;
                    }
                    found = true;
                    break;
                }
            }
            if (found == false) {
                pair <char, int> tempPair(tasks[i], 1);
                taskList.push_back(tempPair);
            }
        }
        
        int total = 0;
        while(true) {
            int count = 0;
            for (int i = 0; i < n + 1; i++) {
                if (i < taskList.size()) {
                    taskList[i].second--;
                    if (taskList[i].second == 0) {
                        taskList.erase(taskList.begin() + i);
                        i--;
                    }
                    total++;
                    count++;
                    if (count == n + 1) {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (taskList.size() == 0) {
                break;
            }
            sort(taskList.begin(), taskList.end(), sortbysec);
            total += (n + 1 - count);
        }
        
        /*
         for (int i = 0; i < taskList.size(); i++) {
         cout << taskList[i].first << " " << taskList[i].second << endl;
         }
         */
        
        return total;
    }
};

#endif /* TaskScheduler_h */
