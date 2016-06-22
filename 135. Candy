class Solution {
public:
    int candy(vector<int>& ratings) {
        int countArray[ratings.size()];
        for(int i =0;i<ratings.size();i++){
            countArray[i] = 1;
        }
        for(int i =1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                countArray[i]=countArray[i-1]+1;
            }
        }
        for(int i =ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                if(countArray[i]<=countArray[i+1])
                    countArray[i]=countArray[i+1]+1;
            }
        }
        int sum =0;
        for(int i = 0;i<ratings.size();i++){
            sum += countArray[i];
        }
        return sum;
    }
    
  
    
};
