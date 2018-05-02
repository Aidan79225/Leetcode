class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string , vector<int>> dp;
        vector<int> ans = part(input, dp);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> part(string input, unordered_map<string ,vector<int>>& dp){
        if(dp.find(input) != dp.end()){
            return dp[input];
        } 
        vector<int> ans;
        int size = input.length();
        for(int i = 0 ; i < size ; i++){
            if(input[i] == '*' || input[i] == '+' || input[i] == '-'){
                vector<int> left =  part(input.substr(0,i), dp);
                vector<int> right =  part(input.substr(i+1), dp);
                cross(input[i],left,right,ans);
            }
        }
        if(ans.size() == 0){
            ans.push_back(stoi(input));
        }
        dp[input] = ans;
        return ans;
    }
    
    void cross(char o, vector<int> left, vector<int> right, vector<int>& ans){
        if(o == '*'){
            for(auto& i : left){
                for(auto& j : right){
                    ans.push_back(i*j);
                }
            }
        }
        if(o == '-'){
            for(auto& i : left){
                for(auto& j : right){
                    ans.push_back(i-j);
                }
            }
        }
        if(o == '+'){
            for(auto& i : left){
                for(auto& j : right){
                    ans.push_back(i+j);
                }
            }
        }
        
    }
    
    
    
};
