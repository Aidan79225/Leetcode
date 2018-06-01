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
        return (c-'0')>=0 && ( '9' - c) >= 0;
    }    
      
};
