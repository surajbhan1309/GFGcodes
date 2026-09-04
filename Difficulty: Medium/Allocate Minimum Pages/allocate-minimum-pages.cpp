class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        long long ans=-1;
        int n=arr.size();
        if(k>n) return -1;
        long long low=*max_element(arr.begin(),arr.end());
        long long high=accumulate(arr.begin(),arr.end(),0LL);
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canalloc(mid,arr,k)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return (int)ans;
    }
    bool canalloc(long long mid,vector<int>&arr,int k){
        int pages=0;
        int students=1;
        for(auto &x:arr){
            if(pages+x<=mid){
                pages+=x;
            }
            else{
                students++;
                pages=x;
            }
        }
        return students<=k;
        
    }
};