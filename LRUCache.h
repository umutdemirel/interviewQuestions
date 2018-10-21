//
//  LRUCache.h
//  
//
//  https://leetcode.com/problems/lru-cache/description/
//

#ifndef LRUCache_h
#define LRUCache_h

class LRUCache {
public:
    unordered_map<int, int> cache;
    vector<int> usedTimes;
    int capacity;
    int numOfCurrentElements;
    
    LRUCache(int capacity) : capacity(capacity), numOfCurrentElements(0) {
        
    }
    
    int get(int key) {
        
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        
        int value = cache[key];
        for (int i = 0; i < usedTimes.size(); i++)
        {
            if (usedTimes[i] == key)
            {
                usedTimes.erase(usedTimes.begin() + i);
                usedTimes.insert(usedTimes.begin(), key);
            }
        }
        return value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end())
        {
            cache[key] = value;
            for (int i = 0; i < usedTimes.size(); i++)
            {
                if (usedTimes[i] == key)
                {
                    usedTimes.erase(usedTimes.begin() + i);
                    usedTimes.insert(usedTimes.begin(), key);
                }
            }
            return;
        }
        numOfCurrentElements++;
        if (numOfCurrentElements > capacity)
        {
            int mapKey = usedTimes[usedTimes.size() - 1];
            usedTimes.pop_back();
            numOfCurrentElements--;
            cache.erase(mapKey);
        }
        usedTimes.insert(usedTimes.begin(), key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#endif /* LRUCache_h */
