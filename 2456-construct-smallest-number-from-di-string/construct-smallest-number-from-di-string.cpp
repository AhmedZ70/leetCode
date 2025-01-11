class Solution {
public:
    string smallestNumber(string pattern) {
        string num(pattern.size() + 1, 0); 
        for (int i = 0; i < num.size(); i++){
            num[i] = i + '1';
        }

        for (int i = 0; i <= pattern.size(); i++){
            if (pattern[i] == 'D'){
                int start = i; 
                while (i < pattern.size() && pattern[i] == 'D'){
                    i++;
                }
                reverse(num.begin() + start, num.begin() + i + 1);
            }
        }
        return num;
    }
};

// "IIIDIDDD"
// Output: "123549876"