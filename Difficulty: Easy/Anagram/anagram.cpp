class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        unordered_map<char,int>map1;
        for(char &x:s1){
            map1[x]++;
        }
        for(char &x:s2){
            map1[x]--;
        }
        for(auto &x:map1){
            if(x.second!=0) return false;
        }
        return true;
        
    }
};