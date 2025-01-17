class Solution {
    // right (0,1) down(1, 0) left (0, -1) up (-1, 0)
    vector<pair<int, int>> directions = {
        {0 , 1}, 
        {1 , 0}, 
        {0 ,-1}, 
        {-1, 0}
    };
    int n, m;
    void traverseMatrix(vector<vector<int>>& matrix, int x, int y, int dir, vector<int>& result, vector<vector<bool>>& visited){
        // condtion to exit
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return; 

        result.push_back(matrix[x][y]);
        visited[x][y] = true;

        int nx = x + directions[dir].first; 
        int ny = y + directions[dir].second;
        
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]){
            dir = (dir + 1) % 4; 
            nx = x + directions[dir].first; 
            ny = y + directions[dir].second;
        }
        traverseMatrix(matrix, nx, ny, dir, result, visited);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(); 
        n = matrix[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        vector<int> result; 
        traverseMatrix(matrix, 0, 0, 0, result, visited);
        return result;
    }
};