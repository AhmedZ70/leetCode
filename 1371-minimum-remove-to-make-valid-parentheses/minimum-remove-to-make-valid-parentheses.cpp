class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> openParens; 
        for (int i = 0; i < s.size(); i++){
            char c = s[i]; 
            if (c == ')'){
                if (!openParens.empty()){
                    openParens.pop(); 
                }
                else{
                    s.erase(i, 1);
                    i--;
                }
            }
            else if (c == '('){
                openParens.push(i);
            }

        }
        while(!openParens.empty()){
            s.erase(openParens.top(), 1);
            openParens.pop();
        }
        return s;
    }
};

/*
steps to solve 
    1. pass thought the array 
        if (open add to stack )
        if it's a ) and we don't have any ( in the stack 
            remove it
        
    store them with inde 

*/