class Solution {
public:
    int countArrangement(int N) {
        bool state[N];
        unordered_map<int,int> mCache;
        for(int i = 0 ; i < N ; i++){
            state[i] = true;
        }
        return dfs(0,state,N,mCache);
    }
    
    int dfs(int index,bool *state,int N,unordered_map<int,int>& mCache){
        if(index >= N){
            return 1;
        }    
        int cacheKey = index;
        for(int i = 0 ; i < N ; i++){
            cacheKey = cacheKey<<1;
            if(state[i]){
                cacheKey += 1;
            }
        }
        if(mCache.find(cacheKey) != mCache.end()){
            return mCache[cacheKey];
        }
        
        int count = 0;
        for(int i = 0 ; i < N ; i++){
            if(state[i] && ((i+1) % (index+1) == 0 || (index+1)%(i+1) == 0 )){
                state[i] = false;
                count += dfs(index+1,state,N,mCache);
                state[i] = true;
            }
        }
        mCache[cacheKey] = count;
        return count;
    }
};
