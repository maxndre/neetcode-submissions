class MedianFinder {
public:
    priority_queue<int, vector<int>, std::greater<int>> bigger; 
    priority_queue<int> smaller;

    MedianFinder() {
        bigger = {};
        smaller = {};
    }
    
    void addNum(int num) {
        int big;
        int small;

        if (smaller.empty()) {
            if (bigger.empty()) {
                smaller.push(num);
                return ;
            }

            big = bigger.top();
            
            if (big > num) {
                smaller.push(num);
                return;
            } else {
                smaller.push(big);
                bigger.pop();
                bigger.push(num);
                return;
            }
        }

        if (bigger.empty()) {
            small = smaller.top();

            if (small < num) {
                bigger.push(num);
                return;
            } else {
                bigger.push(small);
                smaller.pop();
                smaller.push(num);
                return;
            }
        }        

        small = smaller.top();
        big = bigger.top();
        

        if (num < small) {
            if (smaller.size() > bigger.size()) {
                bigger.push(smaller.top());
                smaller.pop();
            }
            smaller.push(num);   
        } else if (big < num) {
            if (bigger.size() > smaller.size()) {
                smaller.push(bigger.top());
                bigger.pop();
            }
            bigger.push(num);   
        } else {
            if (bigger.size() > smaller.size()) {
                smaller.push(num);   
            } else {
                bigger.push(num);   
            }
        }
        
    }
    
    double findMedian() {
        //cout << "bigger.size() = " << bigger.size() << "\n";
        //cout << "smaller.size() = " << smaller.size() << "\n\n";

        if (bigger.size() > smaller.size()) {
            return bigger.top();
        } else if (bigger.size() < smaller.size()) {
            return smaller.top();
        } else {
            double small = smaller.top();
            double big = bigger.top();            
            return big + (small - big)/2;
        }
    }
};





