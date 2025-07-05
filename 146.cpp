// 146. LRU Cache
class LRUCache {
public:
    class ListNode {
    public:
        int key, val;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, ListNode*> mp;
    ListNode *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToFront(ListNode* node) {
        removeNode(node);
        addToFront(node);
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            ListNode* node = mp[key];
            moveToFront(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            ListNode* node = mp[key];
            node->val = value;
            moveToFront(node);
        } else {
            if (mp.size() == cap) {
                // Remove LRU
                ListNode* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            ListNode* newNode = new ListNode(key, value);
            addToFront(newNode);
            mp[key] = newNode;
        }
    }
};
