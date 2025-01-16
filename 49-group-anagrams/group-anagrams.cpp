

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;

        for (const string& s : strs) {
            // Frequency count array (size 26 for a-z)
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;  // Count frequency of each character
            }

            // Convert frequency array into a unique string key
            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#";  // Use '#' as separator
            }

            hashMap[key].push_back(s);
        }

        // Extract grouped anagrams into the result
        vector<vector<string>> result;
        for (auto& [key, group] : hashMap) {
            result.push_back(group);
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