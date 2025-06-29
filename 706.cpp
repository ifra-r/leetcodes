// 706. Design HashMap 
// Design a HashMap without using any built-in hash table libraries.
class MyHashMap {
public:
    vector<pair<int,int>> hm;

    MyHashMap() {
        hm.resize(0);
    }
    
    void put(int key, int value) {
        // already exists?
        for (auto it = hm.begin(); it != hm.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        hm.emplace_back(make_pair(key,value));
    }
    
    int get(int key) {
        for (auto[k,v] : hm) {
            if (k==key)
                return v;
        }
        return -1;
    }
    
    void remove(int key) {
        for (auto it = hm.begin(); it != hm.end(); ++it) {
            if (it->first == key) {
                hm.erase(it);
                break;
            }
        }
    }
};