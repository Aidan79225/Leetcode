class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        //first  : 0, 4, 5, 9,10,12,15,18,20,22,24,26,30
        //second : 2, 1, 3, 2, 1, 2, 1, 3, 2, 3, 1, 1, 3
        vector<pair<int,int>> temp;
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j : nums[i]){
                temp.push_back({j,i});
            }
        }
        sort(temp.begin(),temp.end());
        //first  : 0, 4, 5, 9,10,12,15,18,20,22,24,26,30
        //second : 2, 1, 3, 2, 1, 2, 1, 3, 2, 3, 1, 1, 3
        
        int left = temp[0].first;
        int right = temp[temp.size()-1].first;
        unordered_map<int,int> tempS;
        int count = 0;
        int j = 1;
        if(tempS[temp[0].second]++ == 0)++count;
        for(int i = 0 ;i < temp.size()-1;i++){
            int tempL = temp[i].first;
            while(j < temp.size() && count < k){
                if(tempS[temp[j].second]++ == 0){
                    ++count;
                }
                ++j;
            }
            if(count == k && check(left,right,tempL,temp[j-1].first)){
                left = tempL;
                right = temp[j-1].first;
            }
            tempS[temp[i].second]--;
            if(tempS[temp[i].second] == 0)--count;
        }
        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
    bool check(int tl, int tr, int l, int r){
        return r-l == tr-tl ? l < tl :  r-l < tr-tl;
    }

};
