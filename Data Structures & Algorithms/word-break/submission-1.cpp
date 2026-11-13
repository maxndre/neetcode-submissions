bool explore(string& s, vector<string>& wordDict, int x, vector<int>& memo) {
    if (memo[x] != -1) return memo[x];
    //cout << "x = " << x << "\n";
    int n = s.size();
    bool mismatched;
    bool temp;

    for (string patern : wordDict) {
        //cout << "patern = " << patern << "\n";
        mismatched = false;
        if (x + patern.size() > n) continue;

        for (int i = 0; i < patern.size(); i++) {
            //cout << s[x+i] << " = " << patern[i] << "\n";
            if (char(s[x+i]) != char(patern[i])) {
                mismatched = true; 
                break;
            }
        }
        if (!mismatched) {
            if (x+patern.size() == n) return true;
            //cout << "expore -> " << x+patern.size() << "\n";
            temp = explore(s, wordDict, x+patern.size(), memo);
            memo[x] = temp;
            if (temp) return true;
        }
        
    }
    return false;
}



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end(), [](string a, string b){
            return a.size() > b.size();
        });
        vector<int> memo = vector<int>(s.size(), -1);
        return explore(s, wordDict, 0, memo);
    }
};
