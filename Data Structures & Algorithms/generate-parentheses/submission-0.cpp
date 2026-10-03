void build(int n, string& current, int opened, int stillOpen, vector<string>& output) {
    //cout << "n = " << n << "\n";
    //cout << "current = " << current << "\n";
    //cout << "opened = " << opened << "\n";
    //cout << "stillOpen = " << stillOpen << "\n";
    
    if (current.size() == 2*n && stillOpen == 0) {
        //cout << "yipiii\n";
        //cout << stillOpen << " = 0\n";
        //cout << opened << " = " << n << "\n";
        output.push_back(current);
        return;
    }

    if (opened+1 <= n) {
        current.push_back('(');
        build(n, current, opened+1, stillOpen+1, output);
        current.pop_back();
    } 
    if (stillOpen-1 >= 0) {
        current.push_back(')');
        build(n, current, opened, stillOpen-1, output);
        current.pop_back();
    }


}


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output = {};
        string current;
        build(n, current, 0, 0, output);
        return output;
        
    }
};


