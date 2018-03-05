class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> mystring;
        mystring.reserve(nums.size());
        for(int i=0;i<nums.size();i++){
            mystring.push_back(to_string(nums[i]));
        }
        sort(mystring.begin(),mystring.end(),[](string as, string bs){
                    return as + bs>bs + as;
        });
        for(int i=0;i<nums.size();i++){
            ans += mystring[i];
        }

        while(ans.size()>1 && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};
