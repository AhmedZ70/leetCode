class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk; 
        for (char c : s){
            if (isdigit(c) && !stk.empty()){
                stk.pop(); 
            }
            else{
                stk.push(c);
            }
        }
        string result;
        while(!stk.empty()){
            result += stk.top(); 
            stk.pop();
        }
        reverse(result.begin(), result.end()); 
        return result; 
    }
};