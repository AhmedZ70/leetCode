class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        unordered_map<char, int> letterCounter;
        for (char c : s){
            letterCounter[c]++;
        }
        int oddCount = 0;
        for (auto& [_, count] : letterCounter){
            if (count % 2 != 0){
                oddCount++;
            }
        }
        return (k >= oddCount);
    }
};