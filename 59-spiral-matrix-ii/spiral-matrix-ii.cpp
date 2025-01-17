class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        while (num <= n * n) {
            // Traverse from left to right
            for (int col = left; col <= right; ++col) 
                matrix[top][col] = num++;
            ++top;

            // Traverse from top to bottom
            for (int row = top; row <= bottom; ++row) 
                matrix[row][right] = num++;
            --right;

            // Traverse from right to left
            if (top <= bottom) {
                for (int col = right; col >= left; --col) 
                    matrix[bottom][col] = num++;
                --bottom;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int row = bottom; row >= top; --row) 
                    matrix[row][left] = num++;
                ++left;
            }
        }

        return matrix;
    }
};
