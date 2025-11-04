class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int sum=0;
        int maxi=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==k){
                maxi= i+1;
            }
            if(mp.find(sum-k)!=mp.end()){
                maxi=max(i-mp[sum-k],maxi);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxi;
        
    }
};