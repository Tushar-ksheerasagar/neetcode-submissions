class Solution {
   private:
    int dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int area = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)          
            {
                area += dfs(nr, nc, vis, grid);
            }
        }

        return area;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int area = dfs(i, j, vis, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};