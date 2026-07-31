class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
            }
        }
        int time = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(time,t);
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr < n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc] == 1){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
