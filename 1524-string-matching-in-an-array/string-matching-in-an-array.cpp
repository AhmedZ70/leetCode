class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // intialize a list to hold the result 
        vector<string> result; 
        // iterate through the word in the list 
        for (string word : words){
            for (string other : words){
                if (word == other){
                    continue; 
                }
                if (other.find(word) != string::npos){
                    result.push_back(word);
                    break; 
                }
            }
        }
        return result;
            // compare with every other word
                // skip comparsion with itself

                // check if the current word is a substring of other word



    }
};