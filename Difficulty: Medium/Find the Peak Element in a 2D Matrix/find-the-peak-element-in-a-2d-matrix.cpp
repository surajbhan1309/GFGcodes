#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int max_row = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[max_row][mid]) {
                    max_row = i;
                }
            }
            
            int left_val = (mid - 1 >= 0) ? mat[max_row][mid - 1] : -1000001;
            int right_val = (mid + 1 < m) ? mat[max_row][mid + 1] : -1000001;
            
            if (mat[max_row][mid] >= left_val && mat[max_row][mid] >= right_val) {
                return {max_row, mid};
            }
            else if (left_val > mat[max_row][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};
