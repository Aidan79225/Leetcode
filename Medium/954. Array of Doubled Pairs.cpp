class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        vector<int> p(10001, 0);
        vector<int> n(10000, 0);
        for (auto& it : A) {
            if (it < 0) {
                n[-it - 1]++;
            } else {
                p[it]++;
            }
        }
        
        for (int i = 0, j = 0; i <= 10000; i++){
            j = (i << 1);
            if (p[i] == 0) {
                continue;
            } else if (p[i] < 0) {
                return false;
            } else if (j > 10000) {
                return false;
            } else {
                p[j] -= p[i];
                p[i] = 0;
            }
        }
        
        for (int i = 0, j = 0; i < 10000; i++){
            j = ((i+1) << 1)-1;
            if (n[i] == 0) {
                continue;
            } else if (n[i] < 0) {
                return false;
            } else if (j >= 10000) {
                return false;
            } else {
                n[j] -= n[i];
                n[i] = 0;
            }
        }
        return true;
    }
    
    bool canReorderDoubled2(vector<int>& A) {
        unordered_map<int, set<int>> mMap; // value, set<Index>
        vector<bool> used(A.size(), false);
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
            mMap[A[i]].insert(i);
        }    
        for (int i = 0; i < A.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            int t = A[i];
            mMap[t].erase(i);
            
            int s = t < 0 ? (t>>1) : (t<<1);
            if(s == t && s != 0){
                return false;   
            }
            set<int>& mSet = mMap[s];
            if(mSet.size() == 0){
                return false;
            }
            used[*mSet.begin()] = true;
            mSet.erase(mSet.begin());
        }
        return true;
    }
    
    void printMap(unordered_map<int, set<int>> mMap){
        for (auto& it : mMap){
            cout<<"value : " << it.first<<", index : ";
            for (auto &j : it.second) {
                cout<<j <<",";
            }
            cout<<endl;
        }
    }
    
    bool canReorderDoubled1(vector<int>& A) {
        sort(A.begin(), A.end());
        while (A.size() > 0) {
            // print(A);
            int t = A[0];
            A.erase(A.begin());
            int s = t < 0 ? (t>>1) : (t<<1);
            if(s == t && s != 0)return false;
            bool find = false;
            for (int i = 0; i < A.size(); i++) {
                if(A[i] == s){
                    A.erase(A.begin() + i);
                    find = true;
                    break;
                }
            }
            if (!find) {
                return false;
            }
        }
        return true;
    }
    
    void print(vector<int>& A){
        for (auto& it : A) {
            cout<<it<<", ";
        }
        cout<<endl;
    }
};
