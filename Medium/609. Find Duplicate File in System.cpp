class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mMap;
        for(auto&it : paths){
            string pre = "";
            int i = 0;
            for(; i < it.length() ; i++){
                if(it[i] == ' '){
                    break;
                }
            }
            pre =it.substr(0,i);
            i++;
            
            for(; i < it.length() ; i++){
                int position = i;
                int step = 0;
                while(it[i] != '('){
                    i++;
                    step++;
                }
                string temp = it.substr(position,step);
                i++;
                position = i;
                step = 0;
                while(it[i] != ')'){
                    i++;
                    step++;
                }
                string content = it.substr(position,step);
                mMap[content].push_back(pre+'/'+temp);
                i++;
            }
        }
        vector<vector<string>> ans;
        for(auto&it : mMap){
            if(it.second.size() <= 1){
                continue;
            }
            vector<string> temp;
            for(auto& i : it.second){
                temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
