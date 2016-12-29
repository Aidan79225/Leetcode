// 用index[]  來存 factor 目前成到哪個數最小 
//然後逐次找出每個UglyNumber 
//每次 找到時 同時看看其他數 去除掉一樣的數
class Solution {
public:
    int nthUglyNumber(int n) {
        int index[3] = {0};
        int factor[3] = {2,3,5};
        vector<int> temp;
        temp.push_back(1);
        
        for( int i=1 ; i < n ; i++){
            int min = temp[index[0]] * factor[0];
            int index1 = 0;
            for(int j=0 ; j<3 ; j++){
                int temp1 = temp[index[j]] * factor[j];
                if(temp1 < min){
                    min = temp1;
                    index1 = j;
                }    
            }
            
            temp.push_back(min);
            index[index1]++;
            
            for(int j=0 ; j<3 ; j++){
                if(j == index1)continue;
                
                int temp1 = temp[index[j]] * factor[j];
                if(temp1 == min){
                    index[j]++;
                }    
            }
        }
        return temp[temp.size()-1];
    }
};
