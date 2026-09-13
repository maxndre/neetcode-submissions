float arrivalTime(float position, float speed, float target) {

    // if we are at distance x and speed x -> return 1
    // if we are at distance 0 and speed x -> return 0
    // if we are at distance x+1 and speed x -> return 2
    // if we are at distance x-1 and speed x -> return 1
    // if we are at distance 1 and speed x -> return 1


    if (target - position < 0) { return 0; }

    return (target - position) / speed;
}


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int count = 0;

        // we need to sort the car in posiction order before :
        // we need 

        vector<int> indices(n);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return position[a] > position[b];
        });
        
        float previousArrival = -1;
        float arrival;
        int idx;
        for (int i = 0; i < n; i++) {
            
            idx = indices[i];
            arrival = arrivalTime(position[idx], speed[idx], target);
            if (previousArrival < arrival) {
                // if the previous car arrived before this one, it create a new fleet
                count += 1;
                previousArrival = arrival;
            } 
        }

        return count;
        
        
        
    }
};
