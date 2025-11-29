class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>ans;
        queue<int>q;
        int v=adj.size();
        vector<bool>visited(v,0);
        
        visited[0]=1;
        q.push(0);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return ans;
        
        
    }
};
