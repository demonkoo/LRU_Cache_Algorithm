/**
 * LRU Cache Algorithm
 * Leetcode 146: https://leetcode.com/problems/lru-cache/
 * Written by Skye Koo, 2015-06-04
 */
class LRUCache{
public:
	/**
	 * Set the cache capacity.
	 */
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
	/**
	 * Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	 */
    int get(int key) {
        if (cacheHashMap.find(key) == cacheHashMap.end()) {
            return -1;
        } else {
			// If hit, move the node to the head of list
            cacheList.splice(cacheList.begin(), cacheList, cacheHashMap[key]);
			// Update the iterator of the corresponding key in hash map
            cacheHashMap[key] = cacheList.begin();
            
			return cacheHashMap[key] -> value;
        }
    }
    
	/**
	 * Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
	 */
    void set(int key, int value) {
        if (cacheHashMap.find(key) == cacheHashMap.end()) {
			// If the cache is full, must first remove the least recently used node
            if (cacheList.size() == capacity) {
				// Erase the key of the least recently used node in hash map
                cacheHashMap.erase(cacheList.back().key);
				// Pop the node (alway at the end of the cache)
                cacheList.pop_back();
            }
			// Push the node into the head of list
            cacheList.push_front(CacheNode(key, value));
			// Update the iterator of the corresponding key in hash map
            cacheHashMap[key] = cacheList.begin();
        } else {
			// If the key is already existed, update the corresponding value
            cacheHashMap[key] -> value = value;
			// Move the node to the head of list
            cacheList.splice(cacheList.begin(), cacheList, cacheHashMap[key]);
			// Update the iterator of the corresponding key in hash map
            cacheHashMap[key] = cacheList.begin();
        }
    }
    
private:
    int capacity;
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int key, int value)
        {
            this -> key = key;
            this -> value = value;
        }
    };
    list<CacheNode> cacheList;
	// Use hash map to keep high search efficiency [O(1)]
    unordered_map<int, list<CacheNode>::iterator> cacheHashMap;
};