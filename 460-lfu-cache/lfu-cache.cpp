class LFUCache {
private:
    struct Node {
        int key, value, freq;
        list<int>::iterator it;
    };

    int capacity, minFreq;
    unordered_map<int, Node> keyToNode;
    unordered_map<int, list<int>> freqToKeys;

    void touch(Node &node) {
        // Remove from current frequency list
        freqToKeys[node.freq].erase(node.it);
        if (freqToKeys[node.freq].empty() && node.freq == minFreq) {
            minFreq++;
        }
        // Increase frequency
        node.freq++;
        freqToKeys[node.freq].push_front(node.key);
        node.it = freqToKeys[node.freq].begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) return -1;
        Node &node = it->second;
        touch(node);
        return node.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        auto it = keyToNode.find(key);
        if (it != keyToNode.end()) {
            Node &node = it->second;
            node.value = value;
            touch(node);
            return;
        }

        if (keyToNode.size() == capacity) {
            // Evict LFU key
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            keyToNode.erase(evictKey);
        }

        // Insert new key
        minFreq = 1;
        freqToKeys[1].push_front(key);
        keyToNode[key] = {key, value, 1, freqToKeys[1].begin()};
    }
};
