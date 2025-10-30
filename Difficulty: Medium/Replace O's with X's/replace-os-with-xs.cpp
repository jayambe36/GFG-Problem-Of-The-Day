class Solution {
  public:

    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 'O')

            return;

        grid[i][j] = '#'; // mark as safe

        dfs(i + 1, j, grid, n, m);

        dfs(i - 1, j, grid, n, m);

        dfs(i, j + 1, grid, n, m);

        dfs(i, j - 1, grid, n, m);

    }

 

    void fill(vector<vector<char>>& grid) {

        int n = grid.size();

        int m = grid[0].size();

 

        // Step 1: Mark boundary connected 'O's as safe ('#')

        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 'O') dfs(i, 0, grid, n, m);

            if (grid[i][m - 1] == 'O') dfs(i, m - 1, grid, n, m);

        }

        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 'O') dfs(0, j, grid, n, m);

            if (grid[n - 1][j] == 'O') dfs(n - 1, j, grid, n, m);

        }

 

        // Step 2: Convert surrounded 'O' -> 'X', and safe '#' -> 'O'

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 'O')

                    grid[i][j] = 'X';

                else if (grid[i][j] == '#')

                    grid[i][j] = 'O';

            }

        }

    }

};