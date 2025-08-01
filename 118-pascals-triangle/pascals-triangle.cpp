class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back(vector<int>());
        triangle[0].push_back(1);
        for (int r = 1; r < numRows; r++){
            vector<int> row;
            vector<int> prevRow = triangle[r - 1];
            
            row.push_back(1);
            for (int j = 1; j < r; j++){
                row.push_back(prevRow[j -1] + prevRow[j]);
            }
            row.push_back(1); 
            triangle.push_back(row);
        }
        return triangle;
    }
};