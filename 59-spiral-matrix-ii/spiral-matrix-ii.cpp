class Solution {
    int num = 1; // Current number to fill in the matrix
    vector<pair<int, int>> directions = { // Directions: right, down, left, up
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    void traverseMatrix(vector<vector<int>>& matrix, int x, int y, int dir, int n) {
        if (num > n * n) return; // Stop when all numbers are filled

        matrix[x][y] = num++; // Fill the current cell

        int nx = x + directions[dir].first;
        int ny = y + directions[dir].second;

        // Check if the next cell is out of bounds or already filled
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
            dir = (dir + 1) % 4; // Change direction
            nx = x + directions[dir].first;
            ny = y + directions[dir].second;
        }

        traverseMatrix(matrix, nx, ny, dir, n); // Recurse to the next cell
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        traverseMatrix(matrix, 0, 0, 0, n); // Start at (0, 0) moving right (dir = 0)
        return matrix;
    }
};
