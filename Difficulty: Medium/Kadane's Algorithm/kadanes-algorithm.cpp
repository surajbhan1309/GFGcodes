class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int sum=0;
        int maxi=INT_MIN;
        for(auto &x:arr){
            sum+=x;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};