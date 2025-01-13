class Solution {
public:
    int myAtoi(string s) {
        // skip leading white space
        int i = 0, n = s.size(); 
        long res = 0; 
        int sign = 1; 
        while (i < n && s[i] == ' '){
            i++;
        }
        if (i < n && s[i] == '-' || s[i] == '+'){
            if (s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        while (i < n && isdigit(s[i])){
            res = res * 10 + (s[i] - '0');
            i++;
            
            if (res * sign > INT_MAX){
                return INT_MAX;
            }
            if (res * sign < INT_MIN) {
                return INT_MIN;
            }
        }
        return res * sign;
    }
};