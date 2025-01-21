class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        // Compute prefix sums for both rows
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        
        // Simulate the split point where the first robot moves down
        for (int i = 0; i < n; ++i) {
            // Points left in the top row (after column i)
            long long topRemaining = prefixTop[n] - prefixTop[i + 1];
            // Points left in the bottom row (before column i)
            long long bottomRemaining = prefixBottom[i];
            
            // The second robot will collect the maximum of these two
            long long secondRobotPoints = std::max(topRemaining, bottomRemaining);
            
            // Minimize the maximum points the second robot collects
            result = std::min(result, secondRobotPoints);
        }
        
        return result;
    }
};
