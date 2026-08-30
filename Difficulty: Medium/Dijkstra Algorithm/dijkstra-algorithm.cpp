class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();
            
            if(dist[node]<d) continue;
            
            for(auto &[nbr,w]:adj[node]){
                if(d+w<dist[nbr]){
                    dist[nbr]=d+w;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        return dist;
        
    }
};