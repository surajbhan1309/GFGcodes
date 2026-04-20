class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(partitions(arr,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
    bool partitions(vector<int>&arr,int k,int mid){
        int count=1;
        int sum=0;
        for(int x:arr){
            if(x+sum<=mid){
                sum+=x;
            }
            else{
                count++;
                sum=x;
            }
        }
        return count<=k;
    }
    
};