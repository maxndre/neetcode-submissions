class KthLargest {
public:
    int myK;
    std::priority_queue<int, std::vector<int>, std::greater<int>> oneTwoK;

    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        myK = k;

        oneTwoK.push(-1000);

        int i = 0;

        for (; i < k - 1; i++) { 
            oneTwoK.push(nums[i]);
        }
        
        for (; i < n; i++) {
            if (oneTwoK.top() < nums[i]) {
                oneTwoK.pop();
                oneTwoK.push(nums[i]);
            }
        }        

    }
    
    int add(int x) {

    if (oneTwoK.top() < x) {
        oneTwoK.pop();
        oneTwoK.push(x);
    }

    return oneTwoK.top();

    }
};
