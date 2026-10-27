class Solution {
public:
    int climbStairs(int n) {

        // for 1 -> there a a single way to do (1)
        // for 2 -> 1+1, 2
        // for n+1 -> f(n) + f(n-1) -> we either start with a 1 -> f(n) or a 2 -> f(n-1)
        int A = 0;
        int B = 1;
        int temps;

        for (int i = 0; i < n; i++) {
            temps = B;
            B = A + B;
            A = temps;
            
        }

        return B;
        
    }
};
