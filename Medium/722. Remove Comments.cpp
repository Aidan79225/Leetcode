class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool commentMode = false;
        string s;
        for(int i = 0 ; i < source.size() ; i++){
            string t = source[i];
            for(int j = 0 ; j < t.length() ; ){
                if(!commentMode && t.substr(j,2) == "//"){
                    break;
                }else if(!commentMode && t.substr(j,2) == "/*"){
                    commentMode = true;
                    j+=2;
                }else if(commentMode && t.substr(j,2) == "*/"){
                    commentMode = false;
                    j+=2;
                }else if(!commentMode){
                    s += t[j++];
                }else{
                    ++j;
                }
            }
            if(!commentMode && !s.empty()){
                ans.push_back(s);
                s="";
            }
        }
        return ans;
    }
};
