class LFUCache {
    // map to store the key and value = {value, freq} of the node
    map<int,pair<int,int>> mp1;
    // map to store the key and iterator of the node in dll
    map<int,list<int>::iterator> mp2;
    // map to store the freq and list of corresponding nodes
    map<int,list<int>> mp3;
    int cap,freq,size;
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        freq = 0;
    }
    
    int get(int key) {
        if(mp1.find(key) == mp1.end()) return -1;
        mp3[mp1[key].second].erase(mp2[key]);
        mp1[key].second++;
        mp3[mp1[key].second].push_back(key);
        mp2[key] = --mp3[mp1[key].second].end();
        if(mp3[freq].size() == 0){
            freq++;
        }
        return mp1[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        if(mp1.find(key) != mp1.end()){
            int val = get(key);
            mp1[key].first = value;
            return;
        }
        if(size >= cap){
            mp1.erase(mp3[freq].front());
            mp2.erase(mp3[freq].front());
            mp3[freq].pop_front();
            size--;
        }
        mp1[key] = {value,1};
        mp3[1].push_back(key);
        mp2[key] = --mp3[1].end();
        freq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */