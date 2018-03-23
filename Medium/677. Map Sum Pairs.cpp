class MapSum {
public:
    /** Initialize your data structure here. */
    class Node{
        public:
            int value = 0;
            unordered_map<char,Node*> mMap;
            int getSum(){
                int sum = value;
                for(auto&it : mMap){
                    sum += it.second -> getSum();
                }
                return sum;
            }
        
    };
    Node* root;
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* temp = root;
        int index = 0;
        int len = key.length();
        while(index < len){
            if(temp -> mMap.find(key[index]) == temp -> mMap.end()){
                temp -> mMap[key[index]] = new Node();
            }
            temp = temp -> mMap[key[index++]];
        }
        temp -> value = val;
    }
    
    int sum(string prefix) {
        Node* temp = root;
        int index = 0;
        while(index < prefix.length() ){
            if(temp -> mMap.find(prefix[index]) == temp -> mMap.end()){
                return 0;
            }
            temp = temp -> mMap[prefix[index++]];
        }
        return temp -> getSum();
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
