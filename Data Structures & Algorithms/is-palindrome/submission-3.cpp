bool isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}



class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();

        int plus = 0;
        int minus = 0;



        while (plus <= n-1-minus) {

            while (!isLetter(s[plus]) && plus < n-1-minus) {
                //cout << s[plus] << " --- plus ++; \n";
                plus++;
            }

            while (!isLetter(s[n-1-minus]) && plus < n-1-minus) {
                //cout << s[n-1-minus] << " --- minus ++; \n";
                minus++;
            }            

            if (plus >= n-1-minus) { break; }

            //cout << s[plus] << " - " << plus << "\n";
            //cout << s[n-1-minus] << " - " << minus << "\n";
            
            if (tolower(s[plus]) != tolower(s[n-1-minus])) {
                //cout << plus << " - " << minus;
                return false;
            }

            plus ++;
            minus ++;
        }

        return true;
        
    }
};
