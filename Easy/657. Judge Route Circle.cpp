class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0;
        int v = 0;
        for(auto& it : moves){
            switch(it){
                case 'U':
                    ++v;
                    break;
                case 'D':
                    --v;
                    break;
                case 'L':
                    --h;
                    break;
                case 'R':
                    ++h;
                    break;
            }
        }
        return h == 0 && v == 0;
    }
};
