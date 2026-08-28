class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        if (nums[0] == target) { return 0; }
        if (nums[n-1] == target) { return n-1; }


        int left = 0;
        int right = n-1;
        int middle;
        int middle_value,left_value,right_value;

        while (left < right) {
            middle = left + (right - left) / 2;
            middle_value = nums[middle];
            left_value = nums[left];
            right_value = nums[right];

            if (middle_value == target) { return middle; }



            if (left_value < middle_value and middle_value < right_value) {
                // in order
                if (middle_value < target) {
                    left = middle + 1;
                } else {
                    right = middle;
                }
            } else {
                // pointer is pointing above left_value or bellow right_value

                if (left_value < middle_value) {
                    // middle value is high
                    if (left_value < target and target < middle_value) {
                        right = middle;
                    } else {
                        left = middle + 1;
                    }
                } else {
                    // middle value is low
                    if (middle_value < target and target < right_value) {
                        left = middle + 1;
                    } else {
                        right = middle;
                    }
                }
            }
        }


        return -1;


        
    }
};




/*


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int middle;
        int small;
        int big;

        if (nums[0] < nums[(n+1)/2]) {
            small = 0;
            big = (n+1)/2;
        } else {
            small = (n+1)/2;
            big = 0;
        }

        // nums[small] < nums[big]

        int small_value, big_value, middle_value;

        int i = 0;
        while (small != big and i < 25) {
            i ++;
            small_value = nums[small];
            big_value = nums[big];

            cout << "\n\nsmall : " << small << " -> " << small_value << "\n";
            cout << "big   : " << big << " -> " << big_value << "\n";


            if (target == small_value) { return small; }
            if (target == big_value) { return big; }

            if (small_value < target and target < big_value) {
                // the tager is between the two, normal binary search
                middle = big + (small - big) / 2;
                if (target == nums[middle]) { return middle; }

                if (nums[middle] < target) {
                    small = middle + 1;
                } else {
                    big = middle - 1;
                }

                
            } else {
                cout << "special case \n";
                // the tager is not between the two, special search
                middle = (n + big + (small - big) / 2) % n;
                if (target == nums[middle]) { return middle; }

                cout << "middle = " << middle << "\n";
                
                if (nums[middle] < nums[big]) {
                    // middle is on the low part
                    if (nums[middle] < target and target < nums[big]) {
                        small = middle + 1;
                    } else {
                        big = middle - 1;
                    }
                } else {
                    // middle is on the high part
                    if (nums[small] < target and target < nums[middle]) {
                        big = middle - 1;
                    } else {
                        small = middle + 1;
                    }
                }


            }
        }

        return small;
        
    }
};


*/