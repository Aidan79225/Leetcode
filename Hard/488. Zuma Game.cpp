class Solution {
public:
    class Bundle{
        public:
            char c;
            int count;
            Bundle(char c,int count){
                this -> c = c;
                this -> count = count;
            }
            string getString(){
                stringstream ss;
                ss<<c << count;
                return ss.str();
            }
    };
    unordered_map<string,unordered_map<int,int>> dp;
    int findMinStep(string board, string hand) {
        vector<Bundle> bundles = transferToBundles(board);
        return findMinStep(bundles,0,hand);
    }
    
    void printB(vector<Bundle> bundles){
        for(int i = 0 ; i < bundles.size() ; i++){
            cout<<"["<<bundles[i].c<<","<<bundles[i].count<<"]";
        }
        cout<<endl;
    }
    
    vector<Bundle> transferToBundles(string s){
        vector<Bundle> bundles;
        int count = 0;
        char temp;
        for(int i = 0 ; i < s.size() ; i++){
            temp = s[i];
            count++;
            if(!(i+1 < s.size() && s[i+1] == temp)){
                bundles.push_back(Bundle(temp,count));
                count = 0;    
            }
        }
        return bundles;
    }
    int findMinStep(vector<Bundle> bundles,int index, string hand){
         int mMin = -1;
        if(bundles.size() == 0){
            int count = 0;
            for(int i = 0 ; i < hand.size(); i++){
                count += ((index >> i) & 0b1);
            }
            return count;
        }
        string dpKey = "";
        for(int i = 0 ; i < bundles.size() ; i++){
            dpKey += bundles[i].getString();
        }
        if(dp[dpKey][index] != 0){
            return dp[dpKey][index];
        }
        for(int i = 0 ; i < hand.size(); i++){
            int useHand = (1 << i);
            if((index >> i) & 0b1 == 1){
                continue;
            }else{
                for(int j = 0 ; j < bundles.size() ; j++){
                    if(hand[i] != bundles[j].c)continue;
                    vector<Bundle> b(bundles);
                    if(hand[i] == b[j].c){
                        b[j].count += 1;
                    }
                    b = remove3(b);
                    if (b.size() == 0) {
                         dp[dpKey][index] = 1;
                        return 1;   
                    }
                
                    int minTemp = findMinStep(b,index|useHand,hand);
    
                    if(minTemp != -1){
                        if(mMin < 0 || mMin > minTemp+1){
                            mMin = minTemp + 1;   
                        }
                    }
                }
            }
        }
        dp[dpKey][index] = mMin;
        return mMin;
        
    }
    
    vector<Bundle> remove3(vector<Bundle> b){
        for(int i = 0 ; i<b.size() ; i++ ){
            if(b[i].count >= 3){
                b.erase(b.begin() + i );
                while(i > 0 && b[i].c == b[i-1].c){
                    b[i-1].count += b[i].count;
                    b.erase(b.begin() + i);
                    i--;
                }
                i--;
            }
            
        }
        return b;
    }
};
