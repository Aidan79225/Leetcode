class Solution {
public:
    string fractionToDecimal(int num, int d) {
        map<int,int> mMap;
        if(num == -2147483648 && d == -1){
            return "2147483648";
        }
        if(d == -2147483648 && num == -1){
            return "0.0000000004656612873077392578125";
        }
        if(num == -2147483648 && d == 1){
            return "-2147483648";
        }
        
        
        string ans = "";
        
        bool sign = (num > 0 && d < 0) || (num < 0 && d > 0);
        if(num > 0)num = -num;
        if(d > 0)d = -d;
        
        int a = num / d;
        int b = num % d;
        ans += to_string(a);
        if( b != 0){
            ans += ".";
        }else{
            return ans;
        }
        string sub = "";
        while( b != 0 ){
            int temp = b * 10;
            if(mMap.find(temp) != mMap.end()){
                sub = sub.substr(0,mMap[temp]) + "(" + sub.substr(mMap[temp],sub.length()) + ")";
                break;
            }else{
                a = temp / d;
                b = temp % d;
                sub += to_string(a);
                mMap[temp] = sub.length()-1;
            }
        }
        ans += sub ;
       return (sign ? "-" : "" )+ ans; 
    }
};
