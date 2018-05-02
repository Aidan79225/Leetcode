class Solution {
public:
    class Fraction{
        public:
            Fraction(int top, int bot){
                this -> top = top;
                this -> bot = bot;
            }
            Fraction(string source){
                for(int i = 0 ; i< source.length() ; i++){
                    if(source[i] == '/'){
                        top = stoi(source.substr(0,i));
                        bot = stoi(source.substr(i+1));
                        return;
                    }
                }
            }
            int top;
            int bot;
            void add(Fraction o){
                top *= o.bot;
                o.top *= bot;
                bot *= o.bot;
                o.bot = bot;
                top += o.top;
                normalize();
            }
            void normalize(){
                int g = gcd(top,bot);
                top /= g;
                bot /= g;
                if(bot < 0){
                    top = -top;
                    bot = -bot;
                }
            }
            int gcd(int a, int b){
                if(0 != b) while(0 != (a %= b) && 0 != (b %= a));
	            return a + b;
            }
            string toString(){
                return to_string(top) + '/' + to_string(bot);
            }
    };
    string fractionAddition(string expression) {
        Fraction root(0,1);
        int index = 0;
        int start = 0;
        if(expression[index] == '-'){
            index++;
        }
        int len = expression.length();
        while(index < len){
            if(expression[index] == '+' || expression[index] == '-'){
                root.add(Fraction(expression.substr(start,index-start)));
                start = index;
            }
            index++;
        }
        root.add(Fraction(expression.substr(start,index-start)));
        return root.toString();
    }
};
