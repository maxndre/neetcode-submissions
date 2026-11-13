bool valid(vector<int>& weights, int limit, int capacity) {
    //cout << "\n\n==================\n";
    //cout << "capacity = " << capacity << "\n";
    int n = weights.size();
    int days = 0;
    int sum = 0;
    //cout << "on ajoute ";
    for (int i = 0; i < n; i++) {
        //cout << i << " ";
        if (sum + weights[i] > capacity) {
            days++;
            sum = 0;
            //cout << "\ndays = " << days << "\n";
            //cout << "on ajoute ";
            if (weights[i] > capacity) return false;
            if (days > limit) return false;
        }
        sum += weights[i];
    }
    if (sum != 0) days++;
    return (days <= limit);
}



class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(); // weights < 50 000 (5*10^4)
        // max output : 2.5 * 10^7
        // to test a number we need to go through weights, it is O(n)
        // so we can solve it in 0(n * log(n * 500) ) -> ok

        long long sum = 0;
        for (int i = 0; i < n; i++) sum += weights[i];

        int lower = 0;
        int upper = sum;
        int middle;

        while (lower < upper) {
            middle = lower + (upper - lower)/2;

            if (valid(weights, days, middle)) {
                //cout << "\n ====== OUI ===== \n";
                // middle is valid, so we will go lower
                upper = middle;
            } else {
                //cout << "\n ====== NON ===== \n";
                // middle is not valid, so we will go upper
                lower = middle + 1;
            }
        }

        return lower;

        

    }
};