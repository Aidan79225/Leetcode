class Solution {
public:
    bool isNumber(string s) {
        int i=0,l=s.size(),content = 0,exp = 0;
        if(l==0)return false;                   //長度0
        while(s[i] == ' ')i++;                  //過濾' '
        if(s[i] == '+' || s[i]=='-')i++;        //+ -
        while(isDig(s[i])){i++;content++;}      //數字
        if(s[i] == '.')i++;                     //遇到點
        while(isDig(s[i])){i++;content++;}      //數字
        if(content == 0 )return false;          //沒有數字出現過 例如 ..  .e
        if(s[i] == 'e'){                        //e
            i++;
            if(s[i] == '+' || s[i]=='-')i++;    //+ -
            while(isDig(s[i])){i++;exp++;}      //exp的數字
            if(exp == 0 )return false;          
        }
        while(s[i] == ' ') i++;  
        return i == l;                          //走遍全部
    }
    bool isDig(char c){
        if(c == '0' )return true;
        else if(c == '1' )return true;
        else if(c == '2' )return true;
        else if(c == '3' )return true;
        else if(c == '4' )return true;
        else if(c == '5' )return true;
        else if(c == '6' )return true;
        else if(c == '7' )return true;
        else if(c == '8' )return true;
        else if(c == '9' )return true;
        else return false;
    }    
};
