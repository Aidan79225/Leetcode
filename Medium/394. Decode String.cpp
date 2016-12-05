class Solution {
public:
    string getWord(string s,int& index){
        string ans ="";
        int num =0;
        for(; index<s.size() ; index++){
            if(s[index] - '0' <= 9){
                num *=10;
                num += s[index]-'0';
            }else if(s[index] == '['){
                index++;
                string temp = getWord(s,index);
                for(int j=0;j<num;j++)ans += temp;
                num =0;
            }else if(s[index] == ']'){
                break;
            }
            else{
                ans += s[index];
            }
        }
        return ans;
    }
    string decodeString(string s) {
        string ans ="";
        int size =s.size();
        int index =0;
        while(index < size){
            ans += getWord(s,index);
        }
        return ans;
    }
};
