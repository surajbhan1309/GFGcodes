class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        //prefic sum
        unordered_map<int,int>mp;
        int sum=0;
        int maxlen=0;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) maxlen=max(maxlen,i+1);
            if(mp.count(sum-k)){
                int len=i-mp[sum-k];
                maxlen=max(maxlen,len);
            }
            if(!mp.count(sum)){
                mp[sum]=i;
            }
        }
        return maxlen;
        
    }
};