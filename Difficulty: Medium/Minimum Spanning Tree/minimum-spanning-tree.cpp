class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[V];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto &[nbr,w]:adj[node]){
                if(!vis[nbr]){
                    pq.push({w,nbr});
                }
            }
        }
        return sum;
    }
};