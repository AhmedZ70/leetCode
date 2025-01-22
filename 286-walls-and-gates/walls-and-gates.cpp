class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	    int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int,int>> q; 
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (rooms[i][j] == 0){
					q.push({i, j});
				}
			}
		}

		while(!q.empty()){
			auto [curr_row, curr_col] = q.front();
			q.pop(); 
			
			for (auto [dr, dc] : dirs){

				int new_row = curr_row + dr;
				int new_col = curr_col + dc;

				if (new_row < 0 || new_row >= m ||
                    new_col < 0 || new_col >= n ||
                    rooms[new_row][new_col] != INT_MAX) {

                    continue;
                }
                rooms[new_row][new_col] = rooms[curr_row][curr_col] + 1;
                q.push({new_row, new_col});
			}
		} 
	}
};

