class Solution {
  public:
    int solve(int i,vector<int>&dp,vector<int>&height){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int jumptwo=INT_MAX;
        int jumpone=solve(i-1,dp,height)+abs(height[i]-height[i-1]);
        if(i>1){
            jumptwo=solve(i-2,dp,height)+abs(height[i]-height[i-2]);
        }
        return dp[i]=min(jumpone,jumptwo);
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        vector<int> dp(n,-1);
        return solve(n-1,dp,height);
    }
};