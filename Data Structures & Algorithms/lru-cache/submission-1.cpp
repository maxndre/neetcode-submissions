class LRUCache {
public:

    unordered_map<int, int> cache;
    unordered_map<int, int> counts;
    int count;
    int k;

    queue<int> myQueue;

    LRUCache(int capacity) {
        cache = {};
        counts = {};
        myQueue = {};
        count = 0;
        k = capacity;
    }

    
    int get(int key) {
        bool present = cache.count(key);
        if (present) {
            counts[key]++;
            myQueue.push(key);

            return cache[key];
        }
        return -1;
       
    }
    
    void put(int key, int value) {
        // we need to check if key already existed, if it did, no need to delete anything
        bool present = cache.count(key);
        if (!present) count++;

        cache[key] = value;
        counts[key]++;
        myQueue.push(key);
        

        if (!present && count > k) {
            //cout << "\n\nWE NEED TO ERASE\n";
            // we need to delete something, the key that we didn't saw for the longest time
            int topKey = myQueue.front();
            //cout << "topKey = " << topKey << "\n";
            while (counts[topKey] != 1) {
                counts[topKey]--;
                myQueue.pop();
                topKey = myQueue.front();
                //cout << "topKey = " << topKey << "\n";
            }
            counts.erase(topKey);
            cache.erase(topKey);
            myQueue.pop();
            
        }


        
    }
};
