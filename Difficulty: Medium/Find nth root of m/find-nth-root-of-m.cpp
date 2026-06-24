class Solution {
  public:
    int nthRoot(int n, int m) {
        int low=0;
        int high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=1;
            for(int i=1;i<=n;i++){
                ans*=mid;
                if(ans>m) break;
            }
            if(ans==m) return mid;
            if(ans<m) low=mid+1;
            else high=mid-1;
        }
        return -1;
        
    }
};