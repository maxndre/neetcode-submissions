class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> count;
        count.fill(0);

        for (char task : tasks) {
            count[task - 'A']++;
        }

        sort(count.begin(), count.end());

        int minimalTime = ((count[25] - 1) * (n+1)) + 1;
        int buffer = minimalTime - count[25];

        for (int i = 24; i >= 0; i--) {
            //cout << count[i] << " - " << minimalTime << " " << buffer << "\n";
            if (count[i] == count[25]) {
                //cout << "here\n";
                minimalTime++;
                buffer++;
            }

            if (count[i] == 0) return minimalTime;

            if (buffer == 0) minimalTime += count[i];
            else if (buffer - count[i] >= 0) buffer -= count[i];
            else {
                minimalTime += count[i] - buffer;
                buffer = 0;
            }
        }

        return minimalTime;
    }
};
