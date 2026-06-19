class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
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
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto &[v,w]:adj[u]){
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
        
    }
};