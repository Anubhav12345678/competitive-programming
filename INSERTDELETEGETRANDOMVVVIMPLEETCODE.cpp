class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(pos.count(val))
            return false;
        s.push_back(val);
        pos[val] = s.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
         if(!pos.count(val))
            return false;
        int last = s.back();
        swap(s[pos[val]],s[pos[last]]);
        swap(pos[last], pos[val]);
        pos.erase(val);
        s.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = s.size();
        int random = rand() % n;
        
        return s[random];
    }
    private:
    map<int, int> pos;
    vector<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */