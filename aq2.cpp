#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>> 
        > pq;

        pq.push({grid[0][0], {0,0}});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty()){
            int cost = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(cost > dist[r][c]) continue;

            for(int k=0; k<4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n) {
                    int newCost = cost + grid[nr][nc];

                    if(newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr,nc}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    cout << s.minimumCost(grid);
}
