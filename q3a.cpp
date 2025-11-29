class disjointSet{
    vector<int>rank;
    vector<int>parent;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    
    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionn(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int node = i;
                int wgt = it[1];
                int adjNode = it[0];
                edges.push_back({wgt,{node,adjNode}});
            }
        }
        sort(edges.begin(),edges.end());

        disjointSet ds(V);

        int mstwt=0;
        for(auto it : edges){
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.findUParent(u) != ds.findUParent(v)){
                mstwt +=wt;
                ds.unionn(u,v);
            }
        }
        return mstwt;

    }
};
