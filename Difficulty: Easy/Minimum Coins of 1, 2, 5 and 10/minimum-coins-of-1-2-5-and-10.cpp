class Solution {
  public:
    int findMin(int n) {
        vector<int>change={1,2,5,10};
        int count=0;
        for(int i=change.size()-1;i>=0;i--){
            while(n>=change[i]){
                n-=change[i];
                count++;
            }
        }
        return count;
        
    }
};