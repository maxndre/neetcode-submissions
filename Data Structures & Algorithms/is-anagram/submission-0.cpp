class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (t.size() != n) { return false; }

        array<int, 27> letters_count_s;
        array<int, 27> letters_count_t;

        for (int i = 0; i < 27; i++) {
            letters_count_s[i] = 0;
            letters_count_t[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            letters_count_s[s[i] - 'a'] ++;
            letters_count_t[t[i] - 'a'] ++;
        }

        return letters_count_s == letters_count_t;
        
    }
};
