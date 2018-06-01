class RandomizedCollection {
public:
    unordered_map<int, set<int>> mMap;
    vector<int> count;
    int max = 0;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        set<int> s = mMap[val];
        s.insert(max);
        mMap[val] = s;
        
        if(count.size() == max){
            count.push_back(val);    
        }else{
            count[max] = val;
        }
        
        max ++;
        return s.size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(max==0)return false;
        
        set<int> s = mMap[val];
        if(s.empty() )return false;
        
        int index = *(s.begin());
        s.erase(index);
        mMap[val] = s;
        
        
        count[index]  = count[max-1];
        
        if(count[index] == val){
            s.insert(index);
            s.erase(max-1);
            mMap[val] = s;
            max--;
        }else{
            int val2 = count[index];
            set<int> t = mMap[val2];
            t.erase(max-1);
            t.insert(index);
            mMap[val2] = t;
            max--;   
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return count[rand() % max];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
