class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        map<int,int>mp;
        int n=arr.size();
        long count=0;
        int cxor=0;
        for(int i=0;i<n;i++){
            cxor^=arr[i];
            if(cxor==k){
                count++;
            }
            if(mp.count(cxor^k)){
                count+=mp[cxor^k];
            }
            mp[cxor]++;
        }
        return count;
        
    }
};