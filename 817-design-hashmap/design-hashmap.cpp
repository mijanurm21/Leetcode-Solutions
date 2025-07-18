class MyHashMap {
public:
    unordered_map<int, int> mp;
    set<int> s;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mp[key] = value;
        s.insert(key);
    }
    
    int get(int key) {
        if(s.find(key) != s.end()){
            return mp[key];
        }
        else return -1;
    }
    
    void remove(int key) {
        mp.erase(key);
        s.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */