class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        // Step 1: Compute the maximum character frequencies for words2
        // words 2 -> m*l
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
                maxFreq[c - 'a'] = max(maxFreq[c - 'a'], freq[c - 'a']);
            }
        }

        // Step 2: Filter words1 based on maxFreq
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                result.push_back(word);
            }
        }
        return result;
    }
};
