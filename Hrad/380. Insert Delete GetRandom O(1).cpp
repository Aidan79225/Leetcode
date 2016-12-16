class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> myVector;
    unordered_map<int, int> myMap;
    int stackIndex = 0;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(myMap.count(val)) return false;
        
        myMap[val] = stackIndex;
        if(myVector.size() <= stackIndex) myVector.push_back(val);
        else myVector[stackIndex] = val;
        stackIndex++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(myMap.count(val) == 0) return false;
        int index = myMap[val];
        stackIndex--;
        myMap[myVector[stackIndex]] = index;
        
        int temp = myVector[index];
        myVector[index] = myVector[stackIndex];
        myVector[stackIndex] = temp;
        
        
        return myMap.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int gg = rand() % (stackIndex);
       
        return myVector[gg];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
