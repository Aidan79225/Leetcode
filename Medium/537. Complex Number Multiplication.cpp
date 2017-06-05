class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        CNum x(a);
        CNum y(b);
        return x.mul(b);
    }
    class CNum{
        private:
            int a = 0;
            int b = 0;
        public :
        CNum(string input){
            int index = input.find("+");
            a = stoi(input.substr(0,index));
            b = stoi(input.substr(index+1,input.length()-1));
        }
        string mul(CNum o){
            int r = a * o.getR() - b * o.getI();
            int i = a * o.getI() + b * o.getR();
            return to_string(r) + "+" + to_string(i) + "i";
        }
        int getR(){
            return a;
        }
        int getI(){
            return b;
        }
    };
};
