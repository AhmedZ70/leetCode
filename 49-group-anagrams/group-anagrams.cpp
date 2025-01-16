class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ["eat","tea","tan","ate","nat","bat"]
        // assuming that we have a map with words that have sorted letters
        // #1 iterate over each word
        // #2 sort it 
        // #3 if it doesn't exist in the map
                // we add new list
        // #4 add that work at the index
        vector<vector<string>> result; 
        unordered_map<string, int> index; 
        for (string s : strs){
            string t = s; 
            sort(t.begin(), t.end());
            if (index.find(t) == index.end()){
                index[t] = result.size();
                result.push_back({});
            }
            result[index[t]].push_back(s);
        }
        return result;
    }
};


/*
class Solution {
private: 
    bool isAnagram (string s, string t){
        unordered_map<char, int> counter; 
       for (char c : s){
            counter[c]++;
        }
        for (char c : t){
                counter[c]--;
        }
        for (auto pair : counter){
            if (pair.second != 0){
                return false;
            }
        }
        return true;
    }
    vector<string> checkAnagrams(vector<string>& strs, vector<bool>& isChecked, int index){
        int n = strs.size();
        vector<string> anagrams;
        anagrams.push_back(strs[index]);
        for (int i = index + 1; i < n; i++){
            if (isAnagram(strs[index], strs[i])){
                anagrams.push_back(strs[i]);
                isChecked[i] = true;
            }
        }
        return anagrams;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool> isChecked(strs.size(), false);
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++){
            if (!isChecked[i]){
                res.push_back(checkAnagrams(strs, isChecked, i));
            }
        }
        return res;
    }
};
*/