class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0 ){
            int temp = (n-1) % 26;
            n = (n-1) /  26;
            ans += 'A'+temp;    
        }
        int len = ans.length();
        char temp;
        for(int i=0;i<len/2;i++){
            temp = ans[i];
            ans[i]=ans[len-i-1];
            ans[len-i-1] = temp;
        }
    
    
        
        return ans;
    }
};
