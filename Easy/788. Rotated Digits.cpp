class Solution {
public:
    int rotatedDigits(int N) {
        unordered_map<int,int> temp;
        temp[2] = 5;
        temp[5] = 2;
        temp[6] = 9;
        temp[9] = 6;
        temp[1] = 1;
        temp[0] = 0;
        temp[8] = 8;
        int ans = 0;
        for(int i = 1 ; i <= N ; i++){
            int t = i;
            int nt = 0;
            int carry =1;
            while(t > 0){
                int k = t % 10;
                if(temp.find(t % 10) == temp.end() ){
                    break;
                }
                nt += carry * temp[k]; 
                t /= 10;
                carry *= 10;
            }
            if(t == 0 && nt != i)++ans;
        }
        return ans;
    }
};
