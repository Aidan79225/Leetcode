class Solution {
public:
    class Parentheses{
        public:
            vector<Parentheses> subList;
            Parentheses(string s, int& index){
                if(s[index] != '(') {
                    return;
                }
                while(++index < s.length()){
                    if(s[index] == ')'){
                        break;
                    }
                    subList.push_back(* new Parentheses(s, index));
                }
                
            }
            int getValue(){
                int sum = 0;
                for(auto it : subList){
                    sum += it.getValue();
                }
                return sum == 0 ? 1 : (sum<<1);
            }
    };
    int scoreOfParentheses(string s) {
        int x = 0;
        return ((new Parentheses("("+s+")", x)) -> getValue() >> 1);
    }
};
