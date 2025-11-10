class Solution {
  public:
        int lowerBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int start=0;
        int end=n-1;
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>=target){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
        int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int start=0;
        int end=n-1;
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>target){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int lower_bound=lowerBound(arr,target);
        int upper_bound=upperBound(arr,target);
        return upper_bound-lower_bound;
    }
};
