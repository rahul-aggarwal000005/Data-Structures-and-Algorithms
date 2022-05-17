class LRUCache {
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    list<int> l;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void moveToFirst(int key){
        l.erase(mp[key].first);
        l.push_front(key);
        mp[key].first = l.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        moveToFirst(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.count(key) > 0){
            mp[key].second = value;
            moveToFirst(key);
        }
        else{
            l.push_front(key);
            mp[key] = {l.begin(),value};
            cap--;
        }
        if(cap < 0){
            int k = l.back();
            l.pop_back();
            mp.erase(k);
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */