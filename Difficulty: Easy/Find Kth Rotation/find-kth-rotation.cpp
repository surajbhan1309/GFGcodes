class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(maxi==arr[i]){
                if(i==n-1){
                    return 0;
                }
                return i+1;
            }
        }
    }
};
