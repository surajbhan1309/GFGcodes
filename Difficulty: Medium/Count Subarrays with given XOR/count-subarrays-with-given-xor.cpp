class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,long>f;
        int prefix=0;
        long count=0;
        for(auto &x:arr){
            prefix^=x;
            if(prefix==k) count++;
            int need=prefix^k;
            if(f.find(need)!=f.end()){
                count+=f[need];
            }
            f[prefix]++;
        }
        return count;
        
    }
};