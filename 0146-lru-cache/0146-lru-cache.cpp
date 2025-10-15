class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int limit;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int res = node->val;
        delNode(node);
        addNode(node);
        mp[key] = head->next;
        return res;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
        }

        if (mp.size() == limit) {
            Node* lru = tail->prev;
            delNode(lru);
            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};