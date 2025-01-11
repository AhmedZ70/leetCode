class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letterCounter(26, 0);
        for (char c : s){
            letterCounter[c - 'a']++; 
        }
        for (int i = 0; i < s.size(); i++){
            if (letterCounter[s[i] - 'a'] == 1){
                return i; 
            }
        }
        return -1; 
    }
};
