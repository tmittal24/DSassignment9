class Solution {
  public:
  
  void depthTraversal(int start,vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans){
      int node=start;
      visited[node]=1;
      ans.push_back(node);
      
      for(auto it : adj[node]){
          if(!visited[it]){
              depthTraversal(it,adj,visited,ans);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>visited (n,0);
        vector<int>ans;
        int start=0;
        depthTraversal(start,adj,visited,ans);
        return ans;
    }
};
