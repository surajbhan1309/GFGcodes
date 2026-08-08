class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int,int>mp;
        int pre=0;
        int n=arr.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            pre+=arr[i];
            if(pre==k) maxlen=max(maxlen,i+1);
            if(mp.count(pre-k)){
                int len=i-mp[pre-k];
                maxlen=max(maxlen,len);
            }
            if(!mp.count(pre))
                mp[pre]=i;
        }
        return maxlen;
        
    }
};