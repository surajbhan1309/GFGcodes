// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        return ans_xor(l-1)^ans_xor(r);
    }
    int ans_xor(int n){
        if(n%4==1){
            return 1;
        }
        if(n%4==2){
            return n+1;
        }
        if(n%4==3){
            return 0;
        }
        return n;
    }
};