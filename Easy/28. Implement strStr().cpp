class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1,targetSize = haystack.size(),size = needle.size();
        if(size ==0)return 0;
        for(int i =0;i<targetSize-size+1;i++){
            if(haystack[i] == needle[0]){
                bool flag = true;
                for(int j =0;j < size;j++){
                    if(haystack[i+j] != needle[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return i;
                }
            }
        }
        return -1;
    }
};
