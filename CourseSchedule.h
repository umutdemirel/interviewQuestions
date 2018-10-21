//
//  CourseSchedule.h
//  
//
//  https://leetcode.com/problems/course-schedule/description/
//

#ifndef CourseSchedule_h
#define CourseSchedule_h

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< pair < bool, vector<int>> > map(numCourses, pair<bool, vector<int> >(false, vector<int>()));
        
        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i].first].second.push_back(prerequisites[i].second);
        }
        
        while(true)
        {
            bool found = false;
            bool allVisited = true;
            for (int i = 0; i < numCourses; i++) {
                if (map[i].first == false && map[i].second.size() == 0) {
                    map[i].first = true;
                    for (int j = 0; j < numCourses; j++) {
                        if (i != j) {
                            for (int k = map[j].second.size() - 1; k >= 0 ; k--) {
                                if (map[j].second[k] == i) {
                                    found = true;
                                    map[j].second.erase(map[j].second.begin() + k);
                                }
                            }
                        }
                    }
                }
                else if (map[i].first == false && map[i].second.size() > 0) {
                    allVisited = false;
                }
            }
            if (allVisited == true) {
                return true;
            }
            if (found == false)
            {
                return false;
            }
        }
    }
};

#endif /* CourseSchedule_h */
