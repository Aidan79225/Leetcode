class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lCount=0,mid=0,l=1,r=nums.size()-1;                     
        int preditLeft,preditLeftCount,preditRight,preditRightCount;
        while(r-l>1 ){                      
            mid=(l+r)/2.0;
            lCount=0;
            for(int i=0;i<nums.size();i++)
                if(nums[i]< mid && nums[i]>=l && nums[i]<=r)lCount++;   //lCount統計左邊數
            if(lCount >= mid-l+1)r=mid;                                 //mid-l+1為實際上左邊該有多少 左邊太多 右邊往中靠 
            else l=mid;                                                 //                            左邊太少 左邊往中靠
        }
        preditLeftCount =0;
        preditRightCount =0;
        preditLeft = l;
        preditRight =r;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == preditLeft)preditLeftCount++;                 //檢查是否有兩個以上 
            else if(nums[i] == preditRight)preditRightCount++;          //檢查是否有兩個以上 
        }
        if(preditLeftCount>1)return preditLeft;
        else if(preditRightCount>1)return preditRight;
        else return -1;                                                 //都沒有兩個以上就回傳-1
    }
};
