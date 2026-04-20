class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        if(k>n) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canallocate(arr,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    bool canallocate(vector<int>&arr,int k,int mid){
        int students=1;
        int pages=0;
        for(int x:arr){
            if(x+pages<=mid){
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