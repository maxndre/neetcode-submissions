class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if (prerequisites.empty()) return true;
        
        int leftToTake = 0;

        queue<int> myQueue = {};

        vector<bool> taken = vector<bool>(numCourses, false);



        unordered_map<int, vector<int>> willFree = {}; 
        unordered_map<int, vector<int>> need = {}; 

        for (auto p : prerequisites) {
            willFree[p[1]].push_back(p[0]);
            need[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (need[i].empty()) {
                myQueue.push(i);
                taken[i] = true;
            }
        }

        int course;

        bool flag;

        while (!myQueue.empty()) {
            course = myQueue.front();
            myQueue.pop();
            taken[course] = true;
            for (int maybe : willFree[course]) {
                // maybe is a course that might be freed by course
                flag = true;
                for (int needed : need[maybe]) {
                    // needed are the classes needed to pass maybe
                    if (!taken[needed]) {
                        flag = false;
                        break;
                    }
                }
                if (flag && !taken[maybe]) {
                    // we can take this course, we have every requirement (flag == true)
                    taken[maybe] = true;
                    myQueue.push(maybe);
                }
            }
        }


        for (bool b : taken) if (!b) return false;
        return true;



    }
};
