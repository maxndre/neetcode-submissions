class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        //cout << "n = " << n << "\n"; 
        array<bool, 256> present;
        for (int i = 0; i < 256; i ++) { present[i] = false; }
        int best = 0;
        int front = 0;
        int back = 0;

        for (int back = 0; back < n; back++) { // the back pointer
            //cout << "\n -- back = " << back << " -- \n";
            while (front < n && !present[s[front]]) {
                //cout << "front = " << front << "\n";
                present[s[front]] = true;
                front++;
            } 

            if (best < front - back) {
                //cout << "best = front - back; \n";
                best = front - back;
            }

            
            present[s[back]] = false;
            
        }

        return best;
    }
};
