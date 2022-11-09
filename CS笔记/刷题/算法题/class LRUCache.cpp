class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;//哈希链表
public:
    LRUCache(int capacity) : cap(capacity) {
    }
    //获取key对应的val
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        auto key_value = *map[key];//得到哈希表中key对应链表中的节点<key,val>。
        //将key删除，重新插入到队尾
        cache.erase(map[key]);
        cache.push_front(key_value);
        map[key] = cache.begin();
        return key_value.second;
    }
    //存入键值对
    void put(int key, int value) {
        if (map.find(key) == map.end()) {
            if (cache.size() == cap) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else {
            cache.erase(map[key]);
        }
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};
