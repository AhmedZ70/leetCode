class Solution {
public:
    bool isRobotBounded(string instructions) {
        // "G": go straight 1 unit.
        // "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
        // "R": turn 90 degrees to the right (i.e., clockwise direction).
        vector<pair<int,int>> moves {{0,1}, {1,0}, {0, -1}, {-1, 0}}; 
        int x = 0, y = 0, direction = 0; 
        for (char instr : instructions){
            if (instr == 'R'){
                direction = (direction + 1) % 4;
            }
            else if (instr == 'L'){
                direction = (direction  + 3) % 4; 
            }
            else{
                x += moves[direction].first; 
                y += moves[direction].second;
            }
        }
        return ((x == 0 && y == 0) || direction != 0);
    }
};