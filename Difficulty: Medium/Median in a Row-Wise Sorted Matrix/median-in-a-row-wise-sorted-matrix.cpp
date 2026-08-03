class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<rows;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][cols-1]);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<rows;i++){
                count+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            }
            if(count>(rows*cols)/2){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
