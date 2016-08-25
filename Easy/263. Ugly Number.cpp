class Solution {
public:
    bool isUgly(int num) {
        int temp = num;
        if(!temp)return false;
        while(temp != 1){
            if(! (temp % 2)){
                temp /=2;
            }else if(! (temp % 3)){
                temp /=3;
            }else if(! (temp % 5)){
                temp /=5;
            }else{
                break;
            }
        }
        return temp ==1;
    }
};
