class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> output = {};
        //if (prerequisites.empty()) return true;
        
        queue<int> myQueue = {};

        vector<bool> taken = vector<bool>(numCourses, false);



        vector<vector<int>> willFree = vector<vector<int>>(numCourses, vector<int>(0)); 
        vector<int> needCount = vector<int>(numCourses, 0); 

        for (auto p : prerequisites) {
            willFree[p[1]].push_back(p[0]);
            needCount[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (needCount[i] == 0) {
                myQueue.push(i);
                taken[i] = true;
                output.push_back(i);
                //cout << "output.push_back(i); " << i << "\n";
            }
        }

        int course;

        bool flag;

        while (!myQueue.empty()) {
            course = myQueue.front();
            myQueue.pop();
            //cout << "course = " << course << "\n";
            for (int maybe : willFree[course]) {
                //cout << "maybe = " << maybe << "\n";
                //cout << "needCount[maybe] = " << needCount[maybe] << "\n";
                //cout << "taken[maybe] = " << taken[maybe] << "\n";
                // maybe is a course that might be freed by course
                needCount[maybe]--;
                if (needCount[maybe] == 0 && !taken[maybe]) {
                    taken[maybe] = true;
                    myQueue.push(maybe);
                    output.push_back(maybe);
                    //cout << "output.push_back(maybe); " << maybe << "\n";
                }
            }
        }


        if (output.size() == numCourses) return output;
        return {};



    }
};
