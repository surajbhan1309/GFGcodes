class Solution {
  public:
    int solve(int r, int c, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& memo) {
        if (c < 0 || c >= m) return -1e9;
        if (r == n - 1) return mat[r][c];
        if (memo[r][c] != -1) return memo[r][c];

        int down = solve(r + 1, c, n, m, mat, memo);
        int diag_left = solve(r + 1, c - 1, n, m, mat, memo);
        int diag_right = solve(r + 1, c + 1, n, m, mat, memo);

        return memo[r][c] = mat[r][c] + max({down, diag_left, diag_right});
    }

    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();

        vector<vector<int>> memo(n, vector<int>(m, -1));
        int max_sum = -1e9;

        for (int c = 0; c < m; ++c) {
            max_sum = max(max_sum, solve(0, c, n, m, mat, memo));
        }

        return max_sum;
    }
};
