class MinStack {
public:

    stack<int> mainStack;
    stack<int> minimStack;
        
    MinStack() {

    
    }
    
    void push(int val) {
        mainStack.push(val);

        if (minimStack.empty() || minimStack.top() >= val) {
            minimStack.push(val);
        }
        
    }
    
    void pop() {
        if (!minimStack.empty() && minimStack.top() == mainStack.top()) {
            minimStack.pop();
        }
        mainStack.pop();

    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minimStack.top();
    }
};
