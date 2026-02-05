class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int totalsum=0;
        int n=arr.size();
        for(auto &x:arr){
            totalsum+=x;
        }
        if(totalsum<diff || (totalsum+diff)%2!=0){
            return 0;
        }
        int target=(totalsum+diff)/2;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=target;j>=arr[i];j--){
                dp[j]+=dp[j-arr[i]];
            }
        }
        return dp[target];
        
    }
};