class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    // for [x] -> cost = x
    // for [x, y] -> cost = min(x,y)
    // for [x, y, z] -> cost = min(x+z,y)
    // for [w, x, y, z] -> cost = min(cost([x, y, z]), w + cost([y, z]))

    // either i take the first and then -> a[i] + _a[i+1:]
    // or i don't take i, i take i+1 -> a[i+1] + _a[i+2:]

    vector<int> memo(n);

    memo[n-1] = 0;
    memo[n-2] = min(cost[n-2], cost[n-1]);

    for (int i = n-3; i >= 0; i--) {
        memo[i] = min(cost[i]+memo[i+1], cost[i+1]+memo[i+2]);
        //cout << memo[i] << "\n";
    }

    return memo[0];

    }
};
