class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        return getP(nums,0);
    }
    
    bool getP(vector<int>& nums,int index){
        if(index == 4){
            return reduce4(nums[0],nums[1],nums[2],nums[3]);
        }
        bool ans = false;
        for(int i = index ; i < 4; i++){
            swap(nums[index],nums[i]);
            ans |= getP(nums,index+1);
            swap(nums[index],nums[i]);
        }
        return ans;
    }
    
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    bool reduce2(double a, double b){
        return 
            abs(24 - abs(a-b)) <= 1e-10 || 
            abs(24 - abs(a+b)) <= 1e-10 || 
            abs(24 - abs(a*b)) <= 1e-10 || 
            ( abs(b) <= 1e-10 ? false :abs(24 - abs(a/b)) <= 1e-10);
    }
    bool reduce3(double a, double b, double c){
        return 
            reduce2(a+b,c) ||
            reduce2(a-b,c) ||
            reduce2(a*b,c) ||
            (abs(b) <= 1e-10 ? false : reduce2(a/b,c))||
            reduce2(c,a+b) ||
            reduce2(c,a-b) ||
            reduce2(c,a*b) ||
            (abs(b) <= 1e-10 ? false : reduce2(c,a/b));
    }
    
    
    bool reduce4(double a, double b, double c, double d){
        return 
            reduce3(a+b,c,d) ||
            reduce3(a-b,c,d) ||
            reduce3(a*b,c,d) ||
            (abs(b) <= 1e-10 ? false : reduce3(a/b,c,d)) ||
            reduce3(c,a+b,d) ||
            reduce3(c,a-b,d) ||
            reduce3(c,a*b,d) ||
            (abs(b) <= 1e-10 ? false : reduce3(c,a/b,d)) ||
            reduce3(c,d,a+b) ||
            reduce3(c,d,a-b) ||
            reduce3(c,d,a*b) ||
            (abs(b) <= 1e-10 ? false : reduce3(c,d,a/b));
    }
    
};
