class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;
        for(auto& it : timePoints){
            temp.push_back((it[0]-'0')*600 + (it[1]-'0')*60 + (it[3]-'0')*10 + (it[4]-'0'));
        }
        sort(temp.begin(),temp.end());
        temp.push_back(temp[0]+1440);
        int mMin = 2147483647;
        for(int i = 1 ; i < temp.size();i++){
            mMin = min(mMin, temp[i]-temp[i-1]);
        }
        return mMin;    
    }
};
