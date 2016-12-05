class Solution {
public:
    
    int thirdMax(vector<int>& nums) {
        int a[3] = {INT_MIN};
        int size =nums.size();
        int flag = 0;
        bool hasMin = false;
        for(int i=0;i<size;i++){
            int temp = nums[i];
            if(!hasMin && temp == -2147483648){
                hasMin = true;
                flag++;
            }
            if(temp > a[2]){
                if(temp > a[1]){
                    if(temp > a[0]){
                        a[2] = a[1];
                        a[1] = a[0];
                        a[0] = temp;
                        flag++;
                    }else if (temp < a[0]){
                        a[2] = a[1];
                        a[1] = temp;
                        flag++;
                    }
                }
                else if(temp < a[1]){
                    a[2] = temp;
                    flag++;
                }
            }
        }
        
        return flag >= 3 ? a[2] : a[0];
    }
};
