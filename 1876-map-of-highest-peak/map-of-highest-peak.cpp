class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        //create a new matrix of the same size that is -1 everywhere
        // itirate over the matrix 
        // find the water cells and set them to 0s in the result
        int m = isWater.size(); 
        int n = isWater[0].size(); 
        vector<vector<int>> result(m, vector<int>(n, -1));
        vector<pair<int, int>> dirs = {
            {1, 0}, 
            {0, 1}, 
            {-1, 0},
            {0, -1}
        };
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (isWater[i][j]){
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()){
            auto [curX, curY] = q.front(); 
            q.pop(); 
            for (auto [dirX, dirY] : dirs){
                int newX = curX + dirX; 
                int newY = curY + dirY; 
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && result[newX][newY] == -1){
                    q.push({newX, newY});
                    result[newX][newY] = result[curX][curY] + 1; 
                }
            }
        }

        return result;
    }
};