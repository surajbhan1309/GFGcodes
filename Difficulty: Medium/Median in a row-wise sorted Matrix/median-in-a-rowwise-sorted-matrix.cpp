class Solution {
  public:
    int median(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int low = matrix[0][0];
        int high = matrix[0][col - 1];
        
        for (int i = 1; i < row; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][col - 1]);
        }
        while(low<high){
            int count=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<row;i++){
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<(row*col+1)/2){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
        
    }
};
