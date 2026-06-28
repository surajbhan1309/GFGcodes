class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int left = 0;
        int right = n - 1;

        // Step 1: Find a potential celebrity candidate
        while (left < right) {
            if (mat[left][right] == 1) {
                // If left knows right, left cannot be a celebrity
                left++;
            } else {
                // If left doesn't know right, right cannot be a celebrity
                right--;
            }
        }

        // The potential candidate is at index 'left'
        int candidate = left;

        // Step 2: Verify if the candidate is genuinely a celebrity
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // The celebrity must not know anyone (row must be all 0s)
                // Everyone else must know the celebrity (column must be all 1s except diagonal)
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};
