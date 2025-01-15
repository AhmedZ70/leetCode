class Solution {
    int num = 1;
    void traverseMatrix(vector<vector<int>>& matrix, int dir, int &x, int &y, int n){
        // from current dir, go as much as u can 
        // if reached end of the col/row or hit non 0 
            // rotate 90 degrees 
        if (matrix[x][y] != 0){
            return;
        }
        int m = n;
        int nx = x;
        int ny = y;
        while (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] == 0){
            matrix[nx][ny] = num; 
            nx += directions[dir].first;
            ny += directions[dir].second;
            num++;
        }
        nx -= directions[dir].first;
        ny -= directions[dir].second;
        dir = (dir + 1) % 4;
        nx += directions[dir].first;
        ny += directions[dir].second;
        traverseMatrix(matrix, dir, nx, ny, n);
    }
    // dirctions : 0 -> up, 1 -> right, 2-> down, 3-> left
    vector<pair<int, int>> directions = {
        {-1,0}, {0,1}, {1,0}, {0, -1} 
    };
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n,0));
        if (n == 1){
            matrix[0][0] = 1; 
            return matrix;
        }
        int dir = 1;
        int x = 0, y = 0;
        traverseMatrix(matrix, dir, x, y, n);
        return matrix;
    }
};