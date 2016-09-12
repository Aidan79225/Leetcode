class Solution {
public:
    string convert(string str){
        int len = str.length();
        if(len == 1) return "1" + str;
        string result;
        int count = 1;
        for(int i = 1; i < len; ++i) {
            if(str[i-1] == str[i]) count++;
            else {
                result = result + static_cast<char>(count + '0') + str[i-1];
                count = 1;
            }
            if(i == len - 1) 
                result = result + static_cast<char>(count + '0') + str[i];
        }
        return result;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1;i<n;i++){
            ans = convert(ans);
            
        }
        return ans;
    }
};
