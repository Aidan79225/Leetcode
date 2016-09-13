class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int size = strs.size();
        if(size == 0)return "";
        int minSize = strs[0].size();
        if(minSize == 0)return "";
        for(int i=1;i<size;i++){
            if(minSize > strs[i].size())
                minSize = strs[i].size();
        }
        string ans = "";
        char c;
        bool flag = true;
        for(int i=0;i<minSize;i++){
            c = strs[0][i];
            flag = true;
            for(int j =1;j<size;j++){
                if(strs[j][i] != c){
                    flag = false;
                    break;
                }
            }
            if(flag)ans += c;
            else break;
        }
        return ans;
    }
};
