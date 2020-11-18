class LRUCache {
public:
    map<int,int> mp;
    list<int> q;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        int x = mp[key];
        q.remove(key);
        mp.erase(key);
        q.push_back(key);
        mp[key]=x;
        return x;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            q.remove(key);
            mp.erase(key);       
        }
        if(mp.size()==cap)
        {
            int cur=q.front();
            q.pop_front();
            mp.erase(cur);
        }
        mp[key]=value;
        q.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */