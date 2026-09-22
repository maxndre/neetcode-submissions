class KthLargest {
public:
    int myK;
    vector<int> oneTwoK;

    KthLargest(int k, vector<int>& nums) {
        myK = k;
        oneTwoK = vector<int>(k, -1000);

        for (int x : nums) {
            if (oneTwoK[k-1] < x) {
                oneTwoK[k-1] = x;
            }

            for (int i = k - 2; i >= 0; i --) {

                if (oneTwoK[i] < x) {
                    oneTwoK[i+1] = oneTwoK[i];
                    oneTwoK[i] = x;
                }

            }

        }

    }
    
    int add(int x) {

        if (oneTwoK[myK-1] < x) {
            oneTwoK[myK-1] = x;
        }

        for (int i = myK - 2; i >= 0; i --) {

            if (oneTwoK[i] < x) {
                oneTwoK[i+1] = oneTwoK[i];
                oneTwoK[i] = x;
            }
            
        }

    return oneTwoK[myK-1];

    }
};
