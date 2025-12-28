class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size();   // columns
        int m = grid.size();     // rows
        int ans = 0;

        for (int i = 0; i < m; i++) {        // rows
            for (int j = 0; j < n; j++) {    // columns
                if (grid[i][j] < 0) ans++;
            }
        }
        return ans;
    }
};
