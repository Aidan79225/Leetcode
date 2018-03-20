class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> b(len ,0);
        vector<int> size(len ,0);
        int count = 0;
        for(auto& word : words){
            int t = 0;
            for(auto& c : word){
                t |= 1 << (c - 'a');
            }
            size[count] = word.size();
            b[count++] = t;
        }
        
        int ans = 0;
        for(int i = len-1 ; i >= 1 ; i--){
            for(int j = i-1 ; j >= 0 ; j--){
                int mul = size[i] * size[j];
                if(b[i] & b[j]){
                    continue;
                }
                ans = max(ans, mul);
            }
        }
        return ans;
    }
    int maxProduct1(vector<string>& words) {
        unordered_map<string, int> mMap;
        for(auto& key :  words){
            for(auto& mul :  words){
                if(mMap[key] < mul.size() && !hasCommonChar(key,mul)){
                    mMap[key] = mul.size();
                }
            }
        }
        int ans = 0;
        for(auto& i : mMap){
            int t =i.first.size() * i.second;
            if(ans < t){
                ans = t;
            }
        }
        return ans;
    }
    bool hasCommonChar(string a, string b){
        for(auto& i : a){
            if(b.find(i) != 18446744073709551615){
                return true;
            }
        }
        return false;
    }
};
