class Solution {
public:
    void handleChar(char c){
        if(c >= 'a' && c <= 'z')
            push(c);
        else if(c >= 'A' && c <= 'Z')
            push(c-'A' + 'a');
        else if (c >= '0' && c <= '9')
            push(c);
    }   
    char* stack;
    int index = 0;
    void push(char c ){
        stack[index] = c;
        index++;
    }
    char pop(){
        index--;
        return stack[index];
    }
    bool isPalindrome(string s) {
        stack = (char*)malloc(s.size() * sizeof(char));
        int size = s.size();
        for(int i =0;i<size;i++){
            handleChar(s[i]);
        }
        size = index/2;
        for(int i=0;i<size;i++){
            if(stack[i] != stack[index - i - 1])
                return false;
        }
        return true;
    }
};
