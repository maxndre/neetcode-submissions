class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {



        vector<vector<array<int, 2>>> graph = vector<vector<array<int, 2>>>(n+1);

        vector<int> solution = vector<int>(n+1, INT_MAX);
        vector<bool> done = vector<bool>(n+1, false);

        

        for (int i = 0; i < times.size(); i++) {
            graph[ times[i][0] ].push_back( {times[i][1], times[i][2]} );
            cout << "graph[" << times[i][0] << "].push_back({" << times[i][1] << ", " << times[i][0] << "} )\n";
        }


        // graph[i] -> vector of the destination and time from i 
        // it takes graph[i][1] to get from i to graph[i][0]
        // graph[i][0] -> destination
        // graph[i][1] -> time


        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> myQueue = {};
        // in myQueue : 
        // 1 -> the destination
        // 0 -> our time to get to that point
        
        solution[k] = 0;   
        cout << "solution[" << k << "] = " << solution[k] << "\n";
        myQueue.push({0, k});

        cout << "\n\n";
        while (!myQueue.empty()) {
            
            array<int, 2> temp = myQueue.top();
            myQueue.pop();


            int current = temp[1];
            cout << "\ncurrent = " << temp[1] << "\n";
            if (done[current]) continue;
            done[current] = true;


            for (auto [next, time] : graph[current]) {
                solution[next] = min(solution[next], solution[current] + time);
                cout << "solution[" << next << "] = " << solution[next] << "\n";
                myQueue.push({solution[next], next});
                cout << "pushed : " << solution[next] << ", " << next << "\n";
            }
        }

        int output = solution[1];
        for (int i = 0; i <= n; i++) {
            cout << i << " -> " << solution[i] << "\n";
        }
        for (int i = 1; i <= n; i++) {
            if (solution[i] == INT_MAX) return -1;
            output = max(output, solution[i]);
        }

        return output;
    }
};
