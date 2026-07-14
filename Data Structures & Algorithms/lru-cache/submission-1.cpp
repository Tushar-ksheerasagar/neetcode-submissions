class LRUCache {
   public:
    class Node {
       public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        Node* node = cache[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
            delete cache[key];
            cache.erase(key);
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if (cache.size() > capacity) {
            Node* lru = tail->prev;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};