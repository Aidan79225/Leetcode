class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> mSet;
        for(auto& it : candies)mSet.insert (it);
        return min(mSet.size(), candies.size()/2);
    }
};
