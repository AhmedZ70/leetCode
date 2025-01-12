class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // start at the end of each string 
        int i = s.size() - 1;
        int j = t.size() - 1; 
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0){
            while (i >= 0 && (s[i] == '#' || skipS > 0)){
                if (s[i] == '#'){
                    skipS++;
                }
                else{
                    skipS--;
                }
                i--;
            }
            while (j >= 0 && (t[j] == '#' || skipT > 0)){
                if (t[j] == '#'){
                    skipT++;
                }
                else{
                    skipT--;
                }
                j--;
            }
            if (i < 0 ^ j < 0) return false;
            if (i >= 0 && j >= 0 && s[i] != t[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
        // travese left
        // if a # encountered or the skip is > 0
            // move left
    }
};

// skipS: 1
// skipT: 0
// Input: s = "ac", t = "ac"