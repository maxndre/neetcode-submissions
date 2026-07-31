class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        //cout << "m = " << m << " - n = " << n << "\n";

        if (n == 1 && matrix[0][0] == target) { return true; }
        

        int lower = 0;
        int upper = n*m-1;
        int center = 0;
        


        while (lower < upper) {
            center = (lower+upper)/2;

            //cout << "\nlower = " << lower << " \n";
            //cout << "upper = " << upper << " \n";
            //cout << "center = " << (lower+upper)/2 << "\n";
            //cout << "center/m = " << center/m << "\n";
            //cout << "center%n " << center%n << "\n";





            
            if (matrix[center/m][center%m] < target) {
                //cout << "upper \n";
                lower = (lower+upper)/2;
            } else if (matrix[center/m][center%m] > target) {
                //cout << "lower \n" << matrix[center/m][center%m] << " <- \n";
                upper = (lower+upper)/2;
            } else {
                return true;
            }
            if (upper - lower <= 1) {
                if (matrix[(lower)/m][(lower)%m] == target) {
                    return true;
                }
                if (matrix[(upper)/m][(upper)%m] == target) {
                    return true;
                }
                //cout << "break; \n";
                break;
            }
        }
        //cout << lower << " - " << upper;
        return false;


    }
};
