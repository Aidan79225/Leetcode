class Solution {
public:
    void reverse(string & s){
        int n = s.size();
        for(int i = 0; i < n/2 ; i++){
            char temp = s[i];
            s[i] = s[n-i-1] ;
            s[n-i-1] = temp ;
        }
    }
    string getHint(string secret, string guess) {
        
        int a=0;
        int b=0;
        int size = secret.size();
        bool alock[size];
        bool block[size];
        for(int i = 0 ; i<size ;i++){
            alock[i] = true;
            block[i] = true;
        }
        for(int i = 0 ; i<size ;i++){
            if(secret[i] == guess[i]){
                a++;
                alock[i] = false;
                block[i] = false;
            }
        }
        for(int i = 0 ; i<size ;i++){
            for(int j = 0 ; j<size ; j++){
                if( i == j )continue;
                if((secret[i] == guess[j]) && alock[i] && block[j]){
                    b++;
                    alock[i] = false;
                    block[j] = false;
                } 
            }
        }
        
        string ans = "";
        if(a == 0) ans += '0';
        while(a != 0 ){
            ans += '0' + a % 10;
            a /= 10;
        }
        reverse(ans);
        ans += 'A';
        string temp = "";
        if(b == 0) temp += '0';
        while(b != 0 ){
            temp += '0' + b % 10;
            b /= 10;
        }
        reverse(temp);
        ans += temp;
        ans += 'B';
        
        
        return ans;
    }
};
