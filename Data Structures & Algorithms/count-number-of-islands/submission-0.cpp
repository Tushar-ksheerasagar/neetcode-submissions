class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == '1'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
