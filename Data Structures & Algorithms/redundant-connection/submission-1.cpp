int visit(int start, vector<vector<int>>& graph, unordered_set<int>& seen, 
            unordered_set<int>& cycle, int past) {
    
    seen.insert(start);
    
    int startOfCycle;
    for (int next : graph[start]) {
        if (!seen.count(next)) {
            // new node, we explore
            startOfCycle = visit(next, graph, seen, cycle, start);

            if (startOfCycle != -1 && startOfCycle != next) {
                cycle.insert(next);
                return startOfCycle;
            }
        } else if (next != past) {
            // we are on a cycle. "next" is the start of the cycle
            // we need to return next
            cycle.insert(next);
            return next;
        }

        
        
    }
    return -1;

}


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // n-1+1
        vector<vector<int>> graph = vector<vector<int>>(n+1, vector<int>(0));

        for (vector<int> e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        unordered_set<int> seen = {};
        unordered_set<int> cycle = {};

        visit(1, graph, seen, cycle, -1);


        for (int i = n-1; i >= 0; i--) {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1])) return edges[i];
        }

        return {};

        


    }
};
