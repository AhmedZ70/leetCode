class Solution {
public:
    int firstUniqChar(string s) {
        int res = -1; 
        unordered_map<char, pair<int, int>> letterCounter; 
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            letterCounter[c].first = i;
            letterCounter[c].second++;
        }
        for (char c : s){
            if (letterCounter[c].second == 1){
                res = letterCounter[c].first; 
                break; 
            }
        }
        return res; 
    }
};