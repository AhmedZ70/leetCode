class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // create a map for words2 and a counter for how many times a letter is entions 
        // iterate over each word in word
        // Step 1: Compute the maximum character frequencies for words2
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



// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         // create a map for words2 and a counter for how many times a letter is entions 
//         // iterate over each word in word
//         bool skip = false; 
//         unordered_set<string> resultSet; 
//         unordered_map<string, unordered_map<char, int>> w2Counter; 
//         unordered_set<string> words2Set(words2.begin(), words2.end());
//         for (string word : words2Set){
//             for (char c : word){
//                 w2Counter[word][c]++;
//             }   
//         }
        
//         for (const string& word1 : words1){
//             unordered_map<char, int> w1Counter;
//             for (char c : word1){
//                 w1Counter[c]++;
//             } 
//             for (string word : words2Set){
//                 for (auto p : w2Counter[word]){
//                     if (w1Counter.find(p.first) == w1Counter.end() || w1Counter[p.first] < p.second){
//                     skip = true; 
//                     break; 
//                 }
//                 }   
//             }
//             if (skip){
//                 skip = false; 
//                 continue;
//             }
//             resultSet.insert(word1);
//         }
//         vector<string> result;
//         for (string word : resultSet){
//             result.push_back(word);
//         }
//         return result;
//     }
// };