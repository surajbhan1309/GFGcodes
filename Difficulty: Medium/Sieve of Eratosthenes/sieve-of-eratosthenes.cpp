class Solution {
  public:
    vector<int> sieve(int n) {
        vector<int>primes(n+1,true);
        primes[0]=false;
        primes[1]=false;
        for(int p=2;p*p<=n;p++){
            if(primes[p]==true){
                for(int i=p*p;i<=n;i+=p){
                    primes[i]=false;
                }
            }
        }
        vector<int>ans;
        for(int i=2;i<=n;i++){
            if(primes[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};