class Solution {
private: 
    int num = 1;
    // Directions: right, down, left, up
    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    void traverseMatrix(vector<vector<int>>& matrix, int x, int y, int dir, int n) {
        // Stop when all numbers are filled
        if (num > n * n) return;

        // Fill the current cell
        matrix[x][y] = num++;

        int nx = x + directions[dir].first;
        int ny = y + directions[dir].second;

        // Check if the next cell is out of bounds or already filled
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + directions[dir].first;
            ny = y + directions[dir].second;
        }

        traverseMatrix(matrix, nx, ny, dir, n);
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        // Start at (0, 0) moving right (dir = 0)
        traverseMatrix(matrix, 0, 0, 0, n); 
        return matrix;
    }
};
