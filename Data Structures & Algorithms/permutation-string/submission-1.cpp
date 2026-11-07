bool check(array<int, 26>& count1, array<int, 26>& count2) {
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) return false;
    }
    return true;
}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int l = s1.size();
        if (n < l) return false;

        array<int, 26> count1 = {};
        array<int, 26> count2 = {};

        for (char c : s1) count1[c-'a']++;
        for (int i = 0; i < l; i++) count2[s2[i]-'a']++;
        

        for (int i = l; i < n; i++) {
            if (check(count1, count2)) return true;

            count2[s2[i]-'a']++;
            count2[s2[i-l]-'a']--;
        }
        if (check(count1, count2)) return true;
        return false;

    }
};
