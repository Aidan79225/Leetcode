class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        ans.reserve(n);
        int fizz =3,buzz=5;
        string temp;
        for(int i =1 ;i<=n;i++){
            fizz--;
            buzz--;
            temp= "";
            if( fizz && buzz){
                stringstream ss;
                ss << i;
                temp = ss.str();    
            }else{
                temp = "";
                if(fizz == 0 ){
                    temp += "Fizz";
                    fizz = 3;
                }
                if(buzz == 0){
                    temp += "Buzz";
                    buzz = 5;
                } 
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};
