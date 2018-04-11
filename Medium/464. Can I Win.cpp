class Solution {
public:
    vector<int> mMap;
    bool canIWin(int maxC, int target) {
        if(target == 0){
            return true;
        }
        if(((maxC * (maxC+1))>>1) < target){
            return false;
        }
        int state = 0;
        mMap = vector<int>(1 << maxC, 0);
        bool ans = minimax(state, maxC, target, true);
        return ans;
    }
    bool minimax(int state, int mMax, int target, bool isMe){
        if(target <= 0){
            mMap[state] = !isMe;
            return !isMe;
        }
        if(mMap[state] != 0){
            return mMap[state] > 0;
        }
        bool ans = !isMe;
        for(int i = 0,j = 1 ; i < mMax ; i++, j = j<<1 ){
            if((state & j) == 0){
                bool temp = minimax(state | j, mMax, target-i-1, !isMe);
                if(isMe){
                    ans |= temp;
                    if(ans){
                        break;
                    }
                }else{
                    ans &= temp;
                    if(!ans){
                        break;
                    }
                }
            }
        }
        mMap[state] = ans ? 1 : -1;
        return ans;
    }
};
