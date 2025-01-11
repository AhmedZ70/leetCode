class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> letterCounter; 
        for (char c : s){
            letterCounter[c]++;
        }
        for (int i = 0; i < s.size(); i++){
            if (letterCounter[s[i]] == 1){
                return i; 
            }
        }
        return -1; 
    }
};