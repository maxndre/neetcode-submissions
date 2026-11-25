class Solution {
public:
    string removeKdigits(string num, int k) {
        int K = k;
        int n = num.size();
        int zeros = 0;
        for (char c : num) if (c == '0') zeros ++;
        if (k+zeros >= n) return "0";

        stack<char> myStack = {};
        for (char c : num) {
            while (k > 0 && !myStack.empty() && c < myStack.top()) {
                myStack.pop();
                k--;
            }
            myStack.push(c);
        }

        vector<int> temp = vector<int>(n-K+k, 0);
        //cout << "myStack.size() = " << myStack.size() << "\n";
        for (int i = myStack.size()-1; i >= 0; i--) {
            //cout << "i = " << i << " - " << myStack.top() << "\n";
            temp[i] = myStack.top();
            myStack.pop();
        }
        

        zeros = 0;
        while (temp[zeros] == '0') zeros++;
        //cout << "starting zeros = " << zeros << "\n\n";

        string output = "";
        for (int i = 0; i < n-K-zeros; i++) {
            output.push_back(temp[i+zeros]);
        }

        return output;



    }
};