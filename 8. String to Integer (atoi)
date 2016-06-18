class Solution {
public:
    int myAtoi(string str) {
        int sum =0,i=0;
        bool nega =false,init=false;
        while(str[i] == ' ')i++;
        if(str[i] == '+'){
            i++;
                init=true;
        }else if(str[i] == '-'){
            i++;
            nega =true;
            init = true;
        }
        for(;i<str.length();i++){
            if(isDig(str[i])){
                
                cout<<sum<<endl;
                if(sum == 214748364 && returnDig(str[i])>7)return nega ? 2147483648*-1:2147483647;
                if(sum == 214748364 && returnDig(str[i])==7)return nega ? 2147483647*-1:2147483647;
                else if(sum > 214748364)return nega ? 2147483648*-1:2147483647;
            
                sum = sum*10+returnDig(str[i]);
            }else break;
                
        }
        return nega ? sum*-1:sum;
    }
    bool isDig(char c){
        if(c == '0')return true;
        else if(c == '1')return true;
        else if(c == '2')return true;
        else if(c == '3')return true;
        else if(c == '4')return true;
        else if(c == '5')return true;
        else if(c == '6')return true;
        else if(c == '7')return true;
        else if(c == '8')return true;
        else if(c == '9')return true;
        else return false;
    }
    int returnDig(char c){
        if(c == '0')return 0;
        else if(c == '1')return 1;
        else if(c == '2')return 2;
        else if(c == '3')return 3;
        else if(c == '4')return 4;
        else if(c == '5')return 5;
        else if(c == '6')return 6;
        else if(c == '7')return 7;
        else if(c == '8')return 8;
        else return 9;
    }
};
