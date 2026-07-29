class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> myStack;

        int a;
        int b;

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                a = myStack.top();
                myStack.pop();
                b = myStack.top();
                myStack.pop();
                myStack.push(a+b);
            } else if (tokens[i] == "-") {
                a = myStack.top();
                myStack.pop();
                b = myStack.top();
                myStack.pop();
                myStack.push(b-a);
            } else if (tokens[i] == "/") {
                a = myStack.top();
                myStack.pop();
                b = myStack.top();
                myStack.pop();
                myStack.push(b/a);
            } else if (tokens[i] == "*") {
                a = myStack.top();
                myStack.pop();
                b = myStack.top();
                myStack.pop();
                myStack.push(a*b);
            } else {
                myStack.push(stoi(tokens[i]));
            }
        }
        return myStack.top();
    }
};
