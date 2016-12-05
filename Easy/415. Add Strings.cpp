class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int temp = 0;
        int size = num1.size();
        if(size > num2.size()){
            return addStrings(num2,num1);
        }
        cout<<num1[0]<<endl;
        int i,j;
        for(i = size-1,j=num2.size()-1;i>=0;i--,j--){
            temp = num1[i] + num2[j]-'0'-'0' + carry;
            
            if(temp > 9){
                temp -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            ans = (char)(temp +  '0') + ans;
        }
        
        while(j>=0){
            temp = num2[j]+carry - '0';
            if(temp > 9){
                temp -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            ans = (char)(temp +  '0') + ans;
            
            j--;
        }
        if(carry > 0)ans = '1'+ans;
        
        return ans;
    }
};
