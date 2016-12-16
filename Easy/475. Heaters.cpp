class Solution {
public:
    int dx[3] ={-1,1,0}; 
    int getRadius(int position, vector<int>& heaters,int left,int right){
        int mid = ( left + right ) / 2;
        if(right - left <= 1){
            int ans = INT_MAX;
                for(int i=0;i<3;i++){
                    int index = left+dx[i];
                    if(index >=0 , index < heaters.size())ans = min(ans,abs(position - heaters[left+dx[i]]));
                }
                for(int i=0;i<3;i++){
                    int index = right+dx[i];
                    if(index >=0 , index < heaters.size())ans = min(ans,abs(position - heaters[right+dx[i]]));
                }
            return ans;
        }
        if(position > heaters[mid] ){
            return getRadius(position,heaters,mid+1,right);
        }else{
            return getRadius(position,heaters,left,mid);
        }
        
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = INT_MIN;
        sort(heaters.begin(),heaters.end());
        for(int i =0;i<houses.size();i++){
            ans = max(ans,getRadius(houses[i],heaters,0,heaters.size()));
        }
        return ans;
        
    }
};
