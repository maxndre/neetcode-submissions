class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {




        auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0]*p1[0] + p1[1]*p1[1] > p2[0]*p2[0] + p2[1]*p2[1]; 
        };

        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (auto p : points) {
            pq.push(p);
        }

        vector<vector<int>> output(k);
        for (int i = 0; i < k; i++) {
            output[i] = pq.top();
            pq.pop();
        }

        return output;
    }
};
