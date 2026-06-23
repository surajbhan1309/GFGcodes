class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int cut=1;cut<=i;cut++){
                dp[i]=max(dp[i],price[cut-1]+dp[i-cut]);
            }
        }
        return dp[n];
        
    }
};