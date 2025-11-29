class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       vector<int>vis(V,0);
       long long sum=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});

       while(!pq.empty()){
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();

        if(vis[node]==1) continue;

        //when add to mst then only mark as 1
        vis[node]=1;

        sum=sum+wt;

        for(auto it : adj[node]){
            int adjNode=it[0];
            int weight=it[1];
            if(!vis[adjNode]){
                pq.push({weight,adjNode});
            }
        }
       }
       return sum;
    }
};
