class Solution {
public:
    char* stack;
    int index=0;
    void push(char c){
        stack[index]=c;
        index++;
    }
    char pop(){
        index--;
        return stack[index];
    }
    bool isValid(string s) {
        char c;
        stack = (char*)malloc(s.size() * sizeof(char));
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    push(s[i]);
                    break;
                    
                case ')':
                    c = pop();
                    if(c != '(')   return false;
                    else break;
                    
                case ']':
                    c = pop();
                    if(c != '[')   return false;
                    else break;
                case '}':
                    c = pop();
                    if(c != '{')   return false;
                    else break;
            }
        }
        return index ==0;
    }
};
