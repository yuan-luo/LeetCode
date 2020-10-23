146. LRU缓存机制

https://leetcode-cn.com/problems/lru-cache/

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {
    }
    
    int get(int key) {
        int res = -1;
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            res = it->second->second;
            cacheList.erase(it->second);
            cacheList.push_front(make_pair(key, res));
            cacheMap[key] = cacheList.begin();
        }
        return res;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            cacheList.erase(it->second);
        }

        cacheList.push_front(make_pair(key, value));
        cacheMap[key] = cacheList.begin();
        if (cacheList.size() > cap) {
            int rKey = cacheList.back().first;
            cacheMap.erase(rKey);
            cacheList.pop_back();
        }

    }
private:
    int cap;
    list<pair<int, int>> cacheList; // key/value pair list
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // key : cacheList iterator
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
