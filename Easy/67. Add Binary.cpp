class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size())return addBinary(b,a);
        if(a.size() == 0 && b.size() == 0)return "0";
        string ans = "";
        int i=0;
        int j = b.size()-1;
        int temp =0;
        char c;
        for(i=a.size()-1;i>=0;i--,j--){
            if(a[i] == '0' && b[j] == '0'){
                c='0' + temp;
                temp = 0;
            }
            else if((a[i] == '1' && b[j] == '0')|| (a[i] == '0' && b[j] == '1')){
                if(temp > 0){
                    c = '0';
                    temp = 1;
                }else{
                    c = '1';    
                }
                
                
            }else{
                c='0' + temp;
                temp = 1;
            }
            ans = c + ans;
        }
        for(i = j;i>=0;i--){
            if(b[i] == '0'){
                if(temp > 0 ){
                    c = '1';
                    temp =0;
                }else{
                    c = '0';
                }
            }else{
                if(temp > 0 ){
                    c = '0';
                    temp =1;
                }else{
                    c = '1';
                }
            }
            ans = c + ans;
        }
        if(temp > 0)
            ans = '1'+ans;
        return ans;
    }
};
