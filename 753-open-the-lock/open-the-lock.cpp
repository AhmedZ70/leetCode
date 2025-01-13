class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // create a deadSet 
        unordered_set<string> deadSet (deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q; 
        // create a vesited set
        
        if (deadSet.count("0000")) return -1; 
        // queue : {current string, steps}
        q.push({"0000", 0});
        // if intial position '0000' is in deadSet return -1
        visited.insert("0000");
        // add it to the queue
        while (!q.empty()){
            auto [curr, steps] = q.front(); 
            q.pop(); 
            if (curr == target) return steps;

            for (int i = 0; i < 4; i++){
                // rotate forward add 1 
                string next = curr; 

                next[i] = (curr[i] - '0' + 1) % 10 + '0';
                if (!deadSet.count(next) && !visited.count(next)){
                    q.push({next, steps + 1}); 
                    visited.insert(next);
                }
                // rotate backWard
                string prev = curr; 
                prev[i] = (curr[i] - '0' + 9) % 10 + '0'; 
                if (!deadSet.count(prev) && !visited.count(prev)){
                    q.push({prev, steps + 1});
                    visited.insert(prev); 
                }
            }
        }
        return -1;
        // generate '0000' -> '1000' '9000' 
        // rotating forward and rotating backward each with one step 
    }
};