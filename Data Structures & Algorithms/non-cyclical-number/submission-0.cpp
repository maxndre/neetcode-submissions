int compute(int x) {
    int r;
    int sum = 0;
    while (x > 0) {
        r = x%10;
        //cout << "( r = " << r << " )\n";
        sum += r*r;
        x = x / 10;
    }

    //cout << "sum = " << sum << "\n";
    return sum;
}

// 9 -> 9
// 8 -> 64 -> 10
// 7 -> 49 -> 13 -> 4 -> 16 -> 7
// 6 -> 36 -> 9
// 5 -> 7
// 4 -> 16 -> 7
// 3 -> 9
// 2 -> 4 -> 7
// 1 -> 

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> seen;

        
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = compute(n);
        }
        

        

        return n == 1;

        
    }
};
