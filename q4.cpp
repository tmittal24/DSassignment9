class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(edgeWeight + dis < dist[adjNode]){
                    dist[adjNode]=edgeWeight+dis;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
