

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
