class Node {
   public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    // Insert node immediately after head (Most Recently Used)
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Delete a node from the list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        // Move to front
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        insertAfterHead(newNode);
        mp[key] = newNode;

        // Remove LRU if capacity exceeded
        if (mp.size() > capacity) {
            Node* lru = tail->prev;

            deleteNode(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};