class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n){
            n&=(n-1);
            count++;
        }
        return count;
    }
};