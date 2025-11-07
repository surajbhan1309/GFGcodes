class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<pair<int,pair<int,int>>> maxheap;
        int n=a.size();
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        set<pair<int,int>>visited;
        
        maxheap.push({a[0]+b[0],{0,0}});
        visited.insert({0,0});
        
        vector<int>result;
        
        while(k-- && !maxheap.empty()){
            auto top=maxheap.top();
            maxheap.pop();
            
            int sum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            
            result.push_back(sum);
            
            //next possible 
            if(i+1<n && visited.find({i+1,j})==visited.end()){
                maxheap.push({a[i+1]+b[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            if(j+1<n && visited.find({i,j+1})==visited.end()){
                maxheap.push({a[i]+b[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
           
        }
        return result;
    }
};