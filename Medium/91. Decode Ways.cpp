class Solution {
public:
    int numDecodings(string s,int index){
        int ans =0;
        if(index ==0)return 1;
        if(index > 0 && s[index-1] > '0')ans += numDecodings(s,index-1);
        if (index > 1 && s.substr(index - 2, 2) >= "10" && s.substr(index - 2, 2) <= "26") {
                ans += numDecodings(s,index - 2);
        }
        return ans;
    }
    int numDecodings(string s) {
        if(s.size()==0)return 0;
        int temp[s.size()+1] ={0};
        temp[0]=1;
        if(s[0] -'0' >0)temp[1] = 1;
        for(int i=2;i<=s.size();i++){
            int count =0;
            count +=s[i-1]-'0';
            if(count > 0)temp[i] += temp[i-1];
            count +=10*(s[i-2]-'0');
            if (count >= 10 && count <= 26) temp[i] += temp[i-2];
            
        }
        return temp[s.size()];
    }
};
