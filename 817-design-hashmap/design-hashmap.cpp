class MyHashMap {
private: 
    int BUCKET_SIZE = 1000; 
    vector<list<pair<int, int>>> buckets;

    int hash (int key){
        return key % BUCKET_SIZE; 
    }

public:
    MyHashMap() : buckets(BUCKET_SIZE){
        
    }
    
    void put(int key, int value) {
        int index = hash(key); 
        for (auto& [k, v] : buckets[index]){
            if (k == key){
                v = value; 
                return; 
            }
        }
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        for (const auto& [k, v]: buckets[index]){
            if (k == key){
                return v;
            }
        }
        return -1; 
    }
    
    void remove(int key) {
        int index = hash(key); 
        auto & bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it){
            if (it->first == key){
                bucket.erase(it); 
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */