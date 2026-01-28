class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = chain length
        for(int len = 2; len < n; len++) {

            // start index
            for(int i = 1; i + len - 1 < n; i++) {

                int j = i + len - 1;//last index
                dp[i][j] = INT_MAX;

                // partition point
                for(int k = i; k < j; k++) {
                    int cost = dp[i][k]
                             + dp[k + 1][j]
                             + arr[i - 1] * arr[k] * arr[j];

                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n - 1];
    }
};
