class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> top = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        unordered_set<char> cen = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        unordered_set<char> bot = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        vector<unordered_set<char>> p = {top, cen, bot};
        vector<string> ans;
        for(int i = 0; i<words.size(); i++){
            string s = words[i];
            unordered_set<char> my;
            for(int j=0;j<3;j++){
                if(p[j].count(s[0])){
                    my = p[j];
                    break;
                }
            }
            ans.push_back(s);
            for(int j=1; j<s.size(); j++){
                if(my.count(s[j]) == 0){
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;
    }
};
