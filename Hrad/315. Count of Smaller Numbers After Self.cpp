class Solution {
public:
    void myInsert(vector<int>& temp,int target,int left,int right){
        if(right - left <= 1 ){
            if(target <= temp[left]){
                temp.insert(temp.begin()+left,target);
            }else{
                temp.insert(temp.begin()+right,target);
            }
            return;
        }
        int mid = (left + right)/2;
        if(target >= temp [mid]){
            myInsert(temp,target,mid,right);
        }else{
            myInsert(temp,target,left,mid);
        }
    }
    int getCount(vector<int>& temp,int target,int left,int right){
        if(right - left <= 1 ){
            if(temp[left] == target){
                while(temp[left] == target && left >=0){
                    left--;
                }
                return left+1;
            }
        }
        int mid = (left + right)/2;
        if(target >= temp [mid]){
            return getCount(temp,target,mid,right);
        }else{
            return getCount(temp,target,left,mid);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 ){
            vector<int> ans;
            return ans;
        }
        vector<int> ans(size,0);
        vector<int> temp;
        temp.reserve(size);
        temp.push_back(nums[size-1]);
        
        for(int i=size-2;i>=0;i--){
            int target = nums[i];
            myInsert(temp,target,0,temp.size());
            ans[i] = getCount(temp,target,0,temp.size());
        }
        
        return ans;   
    }
};
