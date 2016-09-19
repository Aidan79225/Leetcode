class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int size = s.size();
        int range = (numRows - 1) * 2; 
        if(range ==0)range =1;
        for(int i = 0 ; i < numRows ; i++){
            for(int j = i ; j < size ; j += range){
                ans += s[j];
                if(i !=0 && i != numRows-1){
                    int temp =j - (i*2) + range;
                    if(temp >= 0 && temp < size){
                        ans += s[temp];
                    }
                }
            }
        }
        return ans;
    }
};
