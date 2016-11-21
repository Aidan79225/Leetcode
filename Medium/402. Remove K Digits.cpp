class Solution {
public:
    string removeKdigits(string num, int k) {
        while(1){
            int i = 1;
            bool has0 = false;
            if(num.size() ==0)return "0";
            if( k == 0 )return num;
            
            if(num.size()>1)
            while(num[i] == '0' && i < num.size()){
                has0 = true;
                i++;
            }
            if(has0) {
                num = num.assign(num, i, num.size()-i);
                k--;
                continue;
            }
        
            for(i=0;i<num.size()-1;i++){
                if(i+1 < num.size())
                if((num[i]-'0')  > (num[i+1]-'0') ){
                    break;
                }
            }
            num.erase(num.begin()+i);
            k--;
        }
        
    }
};
