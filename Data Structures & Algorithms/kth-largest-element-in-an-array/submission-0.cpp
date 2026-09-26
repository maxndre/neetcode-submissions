class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        int n = nums.size();

        pq.push(-100000);

        int i = 0;

        for (; i < k - 1; i++) { 
            pq.push(nums[i]);
        }
        
        for (; i < n; i++) {
            if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        } 

        return pq.top();
    }
};
