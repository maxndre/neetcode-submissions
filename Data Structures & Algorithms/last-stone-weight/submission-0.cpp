/*
The idea would be to use a priority queue to store stones, so that we always have acess to the biggest one. We would then take the biggest stone, check if the queue is empty, if so we return the wiegh, else we take the second biggest, we smash them and we either add the new stone to the queue, or check is the queue is empty (if it's empty, we return 0, else we continue with the two biggest stones)
*/



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> sortedStones;

        for (int stone : stones) {
            sortedStones.push(stone);
        }

        int first;
        int second;

        while (true) {
            

            first = sortedStones.top();
            sortedStones.pop();
            if (sortedStones.empty()) {
                return first;
            }
            
            second = sortedStones.top();
            sortedStones.pop();
            if (second != first) {
                sortedStones.push(first - second);
            } else if (sortedStones.empty()) {
                return 0;
            }
            


        }


    }
};
