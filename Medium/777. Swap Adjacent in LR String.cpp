class Solution {
public:
    bool canTransform(string start, string end) {
        int index = 0;
        int len = start.length();
        int i;
        for(i = 0 ; i < len ; i++){
            if(start[i] == 'X') continue;
            while(end[index] == 'X')index++;
            if(start[i] != end[index]){
                return false;
            }else{
                if(start[i] == 'L' && i < index){
                    return false;
                }else if(start[i] == 'R' && i > index){
                    return false;
                }
            }
            index++;
        }
        while(end[index] == 'X')index++;
        return i == index;
    }
};
