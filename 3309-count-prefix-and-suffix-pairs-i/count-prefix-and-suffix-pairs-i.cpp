class Solution {
    bool isPrefixAndSuffix (string s1, string s2){
        if (s2.substr(0, s1.size()) == s1 && s2.substr(s2.size() - s1.size(), s1.size()) == s1){
            return true;
        }
        return false; 
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); i++){
            for (int j = i + 1; j < words.size(); j++){

                if (isPrefixAndSuffix(words[i], words[j])){
                    res++;
                }
            }
        }
        return res;
    }
};