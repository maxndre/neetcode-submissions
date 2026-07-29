class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<array<int, 2>> myStack;
        vector<int> output(n);

        for (int i = n-1; i >= 0; i--) {
            // myStack is an increasing stack of temperature before 


            while (!myStack.empty() && temperatures[i] >= myStack.top()[0]) {
                myStack.pop();
                // the current temperature is higher than beofre, so we delete low temperature from the stack
            }

            if (!myStack.empty()) {
            output[i] = myStack.top()[1] - i;
            }



            myStack.push({temperatures[i],i});

            

        }
        return output;
    }
};









