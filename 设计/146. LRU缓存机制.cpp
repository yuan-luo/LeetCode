146. LRU缓存机制

https://leetcode-cn.com/problems/lru-cache/

解题思路：

我们用一个cachelist记录这个key/value对的list。用一个cachemap记录某个key的list pair对的iterator游标。
这样从map中就能直接定位找到list中pair的地址。
每次get的时候我们直接通过key找到pair在cachemap中的位置，然后删除它，并在list头加上这个pair对，然后把地址赋给cachemap。
每次put的时候我们先通过key找到pair在cachemap中的位置，如果有就删除它。然后在list头加上这个pair对，让后把地址赋给cachemap，这里多一个删除溢出的值的逻辑，这里删除list最后一个元素。

list<pair<int, int>> cacheList; // key/value pair list
unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // key : cacheList iterator

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
