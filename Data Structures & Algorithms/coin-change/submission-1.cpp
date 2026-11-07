class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // we need a O(c * a) complexity 
        // maybe we can go through every amount lower then amount
        vector<int> number = vector<int>(amount+1, -1);
        number[0] = 0;

        queue<int> myQueue = {};
        myQueue.push(0);

        long long current;

        while (!myQueue.empty()) {
            current = myQueue.front();
            myQueue.pop();

            for (int coin : coins) {
                if (current+coin <= amount && number[current+coin] == -1) {
                    number[current+coin] = number[current]+1;
                    myQueue.push(current+coin);
                }
            }
        }

        return number[amount];

    }
};
