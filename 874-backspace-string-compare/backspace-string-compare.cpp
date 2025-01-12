class Solution {
    string stackToString(stack<char>& stk){
        string s; 
        while (!stk.empty()){
            s += stk.top(); 
            stk.pop(); 
        }
        reverse(s.begin(), s.end());
        return s;
    }
    void addCharsToStack (stack<char>& stk, string s){
        for (char c : s){
            if (c != '#'){
                stk.push(c);
            }
            else{
                if (!stk.empty()){
                    stk.pop();
                }
            }
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk; 
        addCharsToStack(stk, s); 
        s = stackToString(stk);
        addCharsToStack(stk, t); 
        t = stackToString(stk);

        return (s == t);
    }
};