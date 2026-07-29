class Solution {
public:

    string encode(vector<string>& strs) {
        // choose a special character '_'
        // -> "_ " is the signal for a new line
        // -> "_" is the signal for '_'

        int n = strs.size();
        if (n == 0) return "_";

        string str = "";

        for (char c : strs[0]) {
            if (c == '_') {
                str.push_back('_');
                str.push_back('_');
            } else {
                str.push_back(c);
            }
        }
        
        for (int i = 1; i < n; i++) {
            str.push_back('_');
            str.push_back(' ');
            for (char c : strs[i]) {
                if (c == '_') {
                    str.push_back('_');
                    str.push_back('_');
                } else {
                    str.push_back(c);
                }
            }
        }
    return str;

    }

    vector<string> decode(string s) {
        if (s == "_") {return {};}
        int n = s.size();

        vector<string> strs = {};
        string mot = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '_') {
                if (s[i+1] == '_') {
                    mot.push_back('_'); 
                    i++;
                } else {
                    strs.push_back(mot);
                    mot = "";
                    i++;
                }
            } else {
                mot.push_back(s[i]);
            }
        }
        strs.push_back(mot);

        return strs;
        

    }
};
