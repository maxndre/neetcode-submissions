int decode(string& s, int pos, vector<int>& memo) {
    if (memo[pos] != -1) return memo[pos];

    //cout << "pos = " << pos << "\n";
    int n = s.size();
    
    if (pos == n) return 1;
    if (pos == n-1) return (s[n-1] != '0');

    if (s[pos] == '0') return 0;

    if ((s[pos] != '1' && s[pos] != '2')) {
        //cout << "(s[pos] != 1 && s[pos] != 2) \n";
        memo[pos] = decode(s, pos+1, memo);
        return memo[pos];
    }

    if (pos+1 < n && s[pos] == '2' && ('7' <= s[pos+1] && s[pos+1] <= '9')) {
        //cout << "pos+1 < n && s[pos] == 2 && ('7' <= s[pos+1] && s[pos+1] <= '9') \n";
        memo[pos] = decode(s, pos+1, memo);
        return memo[pos];
    }
    else {
        //cout << "else\n";
        // 
        int sum = 0;
        sum += decode(s, pos+1, memo);
        sum += decode(s, pos+2, memo);
        memo[pos] = sum;
        return memo[pos];
    } 
}



class Solution {
public:
    int numDecodings(string s) {
        if (s == "0") return 0;
        int n = s.size();
        if (s[n-1] == '0' && (s[n-2] != '1' && s[n-2] != '2')) return 0;
        vector<int> memo = vector<int>(n+1, -1);
        return decode(s, 0, memo);
    }
};