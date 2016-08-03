class Solution {
public:
    vector<char> str;
    vector<vector<char>> ansStack;
    vector<char> opStack;
    vector<int> ans;
    
    int charToInt(char c){
        switch(c){
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
        }
        return 10;
    }
    bool isNum(char c){
        return charToInt(c)<10;
    }
    bool isAddOrSub(char c){
        return c == '+'? true:c=='-';
    }
    bool isAdd(char c){
        return c == '+';
    }
    bool isSub(char c){
        return c == '-';
    }
    bool isLeft(char c){
        return c == '(';
    }
    bool isRight(char c){
        return c == ')';
    }
    void clearSpace(string s){
        for(int i=0;i<s.size();i++){
            if(s[i] != ' ')
                str.push_back(s[i]);
        }
    }
    int getInt(vector<char> temp){
        int ans=charToInt(temp[0]);
        for(int i=1;i<temp.size();i++){
            ans *= 10;
            ans += charToInt(temp[i]);
        }
        return ans;
    }
    int priority(char c){
        switch(c){
            case '+':case '-':
                return 1;
        }
        return 0;
    }
    void buildData(){
        for(int i=0;i<str.size();i++){
            if(isNum(str[i])){
                vector<char> temp;
                for(int j=i;j<str.size();j++){
                    if(isNum(str[j])) {
                        temp.push_back(str[j]);
                        i++;
                    }
                    else {
                        i =j-1;
                        break;
                    }
                }
                ansStack.push_back(temp);
            }else if(isAdd(str[i])){
                for(int j=opStack.size()-1;j>=0;j--){
                    if(priority(opStack[j])<priority(str[i]))break;
                    vector<char> temp;
                    temp.push_back(opStack[j]);
                    ansStack.push_back(temp);
                    opStack.pop_back();
                }
            
                opStack.push_back(str[i]);
            }else if(isSub(str[i])){
                for(int j=opStack.size()-1;j>=0;j--){
                    if(priority(opStack[j])<priority(str[i]))break;
                    vector<char> temp;
                    temp.push_back(opStack[j]);
                    ansStack.push_back(temp);
                    opStack.pop_back();
                }
                opStack.push_back(str[i]);
            }else if(isLeft(str[i])){
                opStack.push_back(str[i]);
            }else if(isRight(str[i])){
                char c = opStack[opStack.size()-1];
                opStack.pop_back();
                while( c != '(' ){
                    vector<char> temp;
                    temp.push_back(c);
                    ansStack.push_back(temp);
                    c = opStack[opStack.size()-1];
                    opStack.pop_back();
                }
                
            }
        }
        for(int i=0;i<opStack.size();i++){
            vector<char> temp;
            temp.push_back(opStack[i]);
            ansStack.push_back(temp);
        }
    }
    int calculate(string s) {
        clearSpace(s);
        buildData();
        for(int i=0;i<ansStack.size();i++)
        cout<<ansStack[i][0];
        cout<<endl;
        for(int i=0;i<ansStack.size();i++){
            if(isNum(ansStack[i][0])){
                ans.push_back(getInt(ansStack[i]));
            }else if(isAdd(ansStack[i][0])){
                int a= ans[ans.size()-1];
                int b= ans[ans.size()-2];
                ans.pop_back();
                ans.pop_back();
                ans.push_back(a+b);
            }else if(isSub(ansStack[i][0])){
                if(i==1){
                    int a= ans[ans.size()-1];
                    ans.pop_back();
                    ans.push_back(-a);
                    continue;
                }
                int a= ans[ans.size()-1];
                int b= ans[ans.size()-2];
                ans.pop_back();
                ans.pop_back();
                ans.push_back(b-a);
            }
        }
        return ans[0];
    }
    
};
