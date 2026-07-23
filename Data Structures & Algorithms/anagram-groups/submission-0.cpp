class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<array<int,27>, vector<int>> anagrams = {}; // it takes a fingerprint and gives its places in strs``

        array<int,27> fingerprint;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 27; j++) { fingerprint[j] = 0; }
            for (char c : strs[i]) {
                fingerprint[c - 'a'] ++;
            }
            anagrams[fingerprint].push_back(i);
        }

        vector<vector<string>> solution = {};
        vector<string> curent = {};
        vector<int> v;
        for (const auto& [cle, valeur] : anagrams) { // we go through anagrams, we are at anagrams[i] -> a fingerprint
            curent = {};
            for (int i : valeur) {
                curent.push_back(strs[i]);
            }
            solution.push_back(curent);
        }

        return solution;

    }
};
