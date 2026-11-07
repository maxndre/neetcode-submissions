int most(array<int, 26> count) {
    int maxId = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > count[maxId]) maxId = i;
    }
    return count[maxId];
}



class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        array<int, 26> count = {};
        count[s[0]-'A']++;

        int head = 0;
        int maxi = k;

        for (int tail = 0; tail < n-k; tail++) {
            //cout << "\n\n === " << tail << " === \n";
            // for each letter
            
            while (most(count) + k >= head - tail + 1 && head < n) {
                maxi = max(maxi, head - tail + 1);
                //cout << "head++;\n";
                ////cout << "most(count) = " << most(count) << "\n";
                ////cout << "most(count) + k = " << (most(count) + k) << "\n";
                ////cout << "head = " << head << "\n";
                ////cout << "head - tail + 1 = " << (head - tail + 1) << "\n";
                head++;
                count[s[head]-'A']++;
            }
            //cout << "most(count) = " << most(count) << "\n";
            //cout << "most(count) + k = " << (most(count) + k) << "\n";
            //cout << "head = " << head << "\n";
            //cout << "head - tail + 1 = " << (head - tail + 1) << "\n";                

            

            // avancer : 
            // head++; 
            // count[head]++;



            count[s[tail]-'A']--;
        }

        return maxi;
    }
};
