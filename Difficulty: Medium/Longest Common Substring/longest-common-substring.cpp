// class Solution {
//   public:
//     int longestCommonSubstr(string& s1, string& s2) {
//         int n = s1.size(), m = s2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         int ans = 0;

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 if (s1[i - 1] == s2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                     ans = max(ans, dp[i][j]);
//                 } else {
//                     dp[i][j] = 0; // reset because substring must be continuous
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int dp[1001][1001];
    
    int longCommSubstr(string& s1, string& s2) {
        memset(dp, -1, sizeof(dp));
        int maxLength = 0;
        
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                maxLength = max(maxLength, solve(s1, s2, i, j));
            }
        }
        return maxLength;
    }

    int solve(string& s1, string& s2, int i, int j) {
        if (i == s1.length() || j == s2.length()) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        } else {
            dp[i][j] = 0; 
        }

        return dp[i][j];
    }
};
