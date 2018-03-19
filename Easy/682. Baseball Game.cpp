class Solution {
public:
    vector<int> temp;
    int index = 0;
    int calPoints(vector<string>& ops) {
        temp.resize(ops.size());
        for(auto& it :  ops){
            if(it == "+"){
                push(temp[index-1] + temp[index-2]);
            }else if(it == "C"){
                pop();
            }else if(it == "D"){
                push(temp[index-1]<<1);
            }else{
                push(stoi (it,nullptr,0));
            }
        }
        int sum = 0;
    
        for(int i = 0 ; i < index ; i++){
            sum += temp[i];
        }
        return sum;
    }
    
    void push(int a){
        temp[index] = a;
        index++;
    }
    
    void pop(){
        index--;
    }
    
};
