class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> mSet;
        for(string &it : words){
            string t = "";
            for(int i = 0 ; i < it.length() ; i++){
                t += v[it[i] - 'a'];
            }
            if (mSet.find(t)==mSet.end())  
                mSet.insert(t);
        }
        
        return mSet.size();
    }
};
