class Solution {
  public:
    int dp[201][10000];
    bool solve(vector<int>&arr,int i,int sum){
        if(sum==0) return true;
        if(sum<0 || i>=arr.size()) return false;
        if(dp[i][sum]!=-1) return false;
        
        bool take=solve(arr,i+1,sum-arr[i]);
        bool not_take=solve(arr,i+1,sum);
        
        return dp[i][sum]=take|not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,sum);
    }
};