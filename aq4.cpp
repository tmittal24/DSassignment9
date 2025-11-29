class Solution {
  public:
  
  void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&vec,int row0,int col0){
      vis[row][col]=1;
      vec.push_back({row-row0,col-col0});
      
      int n=grid.size();
      int m=grid[0].size();
      
      int drow[]={-1,0,1,0};
      int dcol[]={0,1,0,-1};
      
      for(int i=0;i<4;i++){
          int nrow=row+drow[i];
          int ncol=col+dcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
              bfs(nrow,ncol,grid,vis,vec,row0,col0);
          }
      }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vector<pair<int,int>>vec;
                    bfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
 
