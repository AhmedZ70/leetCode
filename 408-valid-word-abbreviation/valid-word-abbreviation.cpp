class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {  // If it's a digit
                if (abbr[j] == '0') return false;  // Leading zero is invalid

                int num = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num;  // Move forward in the word
            } 
            else {  // If it's a letter
                if (word[i] != abbr[j]) return false;
                i++, j++;
            }
        }
        
        return i == word.size() && j == abbr.size();
    }
};
