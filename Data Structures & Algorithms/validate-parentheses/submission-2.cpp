class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        std::stack<char> myStack;

        

        for (int i = 0; i < n; i++) {

            if (myStack.empty()) {
                myStack.push(s[i]);
            } else {

                if (s[i] == ')') {
                    if (myStack.top() != '(') {
                        return false;
                    } 
                    myStack.pop();
                } else if (s[i] == '}') {
                    if (myStack.top() != '{') {
                        return false;
                    } 
                    myStack.pop();
                } else if (s[i] == ']') {
                    if (myStack.top() != '[') {
                        return false;
                    } 
                    myStack.pop();
                } else {
                    myStack.push(s[i]);
                }

            }
        }

        if (myStack.empty()) { return true; }
        return false;
    }
};
