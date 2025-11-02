class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 0 = empty, 1 = guard, 2 = wall, 3 = guarded cell

        for (auto g : guards) grid[g[0]][g[1]] = 1;
        for (auto w : walls)  grid[w[0]][w[1]] = 2;

        for (auto g : guards) {
            int row = g[0];
            int col = g[1];

            for (int r = row - 1; r >= 0; r--) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }

            for (int r = row + 1; r < m; r++) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                grid[r][col] = 3;
            }

            for (int c = col - 1; c >= 0; c--) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }

            
            for (int c = col + 1; c < n; c++) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                grid[row][c] = 3;
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};
