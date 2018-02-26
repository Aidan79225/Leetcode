class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<int> temp;
        for(auto& it : J){
            temp.insert(it);
        }
        int count = 0;
        for(auto& it : S){
            if(temp.find(it)!=temp.end()){
                count++;
            }
        }
        return count;
    }
};
