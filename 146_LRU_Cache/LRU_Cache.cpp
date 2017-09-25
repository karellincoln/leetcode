class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity){}

    int get(int key) {
        auto it = map_.find(key);

        if (it == map_.end()) {
            return -1;
        }
        else {
            list_.splice(list_.begin(), list_, it->second);
        }
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map_.find(key);

        if(it != map_.end()){
            it->second->second = value;
            list_.splice(list_.begin(), list_, it->second);
            return;
        }
        else if (map_.size() == capacity_) {
            int key = list_.back().first;
            list_.pop_back();
            map_.erase(key);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }

private:
    size_t capacity_;
    list<pair<int,int> > list_;
    unordered_map<int, list<pair<int, int> >::iterator> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */