class Solution {
public:
    class GroupOfAtoms{
        public :
            unordered_map<string,int> mMap;
            int last;
            string key = "";
            int num = 0;
            GroupOfAtoms* sub = nullptr;
            GroupOfAtoms(string s,int start){
                while(s[start] != ')'){
                    if(isNum(s[start])){
                        num *= 10;
                        num += s[start]-'0';
                        start++;
                    }else{
                        if(s[start] == '(' || isUpper(s[start])){
                            calculate();
                        }
                        if(s[start] == '('){
                            sub = new GroupOfAtoms(s,start + 1);
                            start = (sub -> last)+1;
                        }else if(isUpper(s[start]) || isLower(s[start])){
                            key += s[start];
                            start++;  
                        }
                    }
                }
                calculate();
                last = start;
            }
            bool isNum(char c){
                return c >= '0' && c <= '9';
            }
            bool isUpper(char c){
                return c >= 'A' && c <= 'Z';
            }
            bool isLower(char c){
                return c >= 'a' && c <= 'z';
            }
            void getMul(int mul){
                for (auto& kv : mMap) {
                    kv.second *= mul;
                }
            }
            void mergeGroup(GroupOfAtoms* g){
                for (auto& kv : g -> mMap) {
                    mMap[kv.first] += kv.second;
                }
            }
            void calculate(){
                if(key.length() != 0){
                    mMap[key] += max(num,1);
                    key = "";
                    num = 0;
                }
                if(sub != nullptr ){
                    sub -> getMul(max(num,1));
                    mergeGroup(sub);
                    sub = nullptr;
                    num = 0;
                }
            }
            static bool cmp(const pair<string, int>  &p1, const pair<string, int> &p2){
                string key1 = p1.first;
                string key2 = p2.first;
                int ans = key1[0]-key2[0];
                if(ans == 0){
                    if(key1.length() == 1){
                        if(key2.length() == 1){
                            return true;
                        }else{
                            return true;
                        }
                    }else{
                        if(key2.length() == 1){
                            return false;
                        }else{
                            ans = key1[1]-key2[1];
                        }
                    }
                }
                return ans<0;
            }
            string toString(){
                string ans = "";
                vector<pair<string, int> > v;
                copy(mMap.begin(), mMap.end(), back_inserter(v));
                sort(v.begin(), v.end(), cmp);
                for (auto& kv : v) {
                    if(kv.second == 1){
                        ans += kv.first;    
                    }else{
                        stringstream ss;
                        ss << kv.second;
                        ans += kv.first + ss.str();    
                    }
                }
                return ans;
            }
    };
    string countOfAtoms(string formula) {
        formula += ")";
        return GroupOfAtoms(formula,0).toString();
    }
};
