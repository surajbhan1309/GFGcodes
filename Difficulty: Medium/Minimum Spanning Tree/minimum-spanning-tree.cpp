class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[V];
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            auto[wt,node]=pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            
            for(auto [nbr,weight]:adj[node]){
                if(!vis[nbr]){
                    pq.push({weight,nbr});
                }
            }
        }
        return sum;
        
    }
};